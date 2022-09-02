/*****************************************************************************
#                                                                            *
# Copyright 2020 AT&T Intellectual Property                                  *
# Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved.      *
#                                                                            *
# Licensed under the Apache License, Version 2.0 (the "License");            *
# you may not use this file except in compliance with the License.           *
# You may obtain a copy of the License at                                    *
#                                                                            *
#      http://www.apache.org/licenses/LICENSE-2.0                            *
#                                                                            *
# Unless required by applicable law or agreed to in writing, software        *
# distributed under the License is distributed on an "AS IS" BASIS,          *
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
# See the License for the specific language governing permissions and        *
# limitations under the License.                                             *
#                                                                            *
******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "e2sim.hpp"
#include "e2sim_defs.h"
#include "e2sim_sctp.hpp"
#include "e2ap_message_handler.hpp"
#include "encode_e2apv1.hpp"
#include "RANfunctionOID.h"

using namespace std;

int client_fd = 0;

std::unordered_map<long, encoded_ran_function_t *> E2Sim::getRegistered_ran_functions() {
  return ran_functions_registered;
}

void E2Sim::register_subscription_callback(long func_id, SubscriptionCallback cb) {
  logger_debug("about to register callback for subscription for func id %ld", func_id);
  subscription_callbacks[func_id] = cb;
}

void E2Sim::register_control_callback(long func_id, ControlCallback cb) {
  logger_debug("about to register callback for control for func id %ld", func_id);
  control_callbacks[func_id] = cb;
}

SubscriptionCallback E2Sim::get_subscription_callback(long func_id) {
  logger_debug("we are getting the subscription callback for func id %ld", func_id);
  SubscriptionCallback cb;

  try {
    cb = subscription_callbacks.at(func_id);
  } catch(const std::out_of_range& e) {
    throw std::out_of_range("Function ID is not registered");
  }
  return cb;

}

ControlCallback E2Sim::get_control_callback(long func_id) {
  logger_debug("we are getting the control callback for func id %ld", func_id);
  ControlCallback cb;

  try {
    cb = control_callbacks.at(func_id);
  } catch(const std::out_of_range& e) {
    throw std::out_of_range("Function ID is not registered");
  }
  return cb;

}

void E2Sim::register_e2sm(long func_id, encoded_ran_function_t *ran_func) {

  //Error conditions:
  //If we already have an entry for func_id

  logger_debug("about to register e2sm func id %ld", func_id);

  ran_functions_registered[func_id] = ran_func;

}


void E2Sim::encode_and_send_sctp_data(E2AP_PDU_t* pdu, struct timespec *ts)
{
  uint8_t       *buf;
  sctp_buffer_t data;

  data.len = e2ap_asn1c_encode_pdu(pdu, &buf);
  memcpy(data.buffer, buf, min(data.len, MAX_SCTP_BUFFER));
  if (buf) free(buf);

  sctp_send_data(client_fd, data, ts);
}


void E2Sim::wait_for_sctp_data()
{
  struct timespec ts; // timestamp of the received message
  sctp_buffer_t recv_buf;
  if(sctp_receive_data(client_fd, recv_buf, &ts) > 0)
  {
    logger_info("[SCTP] Received new data of size %d", recv_buf.len);
    e2ap_handle_sctp_data(client_fd, recv_buf, false, this, &ts);
  }
}



void E2Sim::generate_e2apv1_subscription_response_success(E2AP_PDU *e2ap_pdu, long reqActionIdsAccepted[], long reqActionIdsRejected[], int accept_size, int reject_size, long reqRequestorId, long reqInstanceId) {
  encoding::generate_e2apv1_subscription_response_success(e2ap_pdu, reqActionIdsAccepted, reqActionIdsRejected, accept_size, reject_size, reqRequestorId, reqInstanceId);
}

void E2Sim::generate_e2apv1_indication_request_parameterized(E2AP_PDU *e2ap_pdu, e_RICindicationType indicationType, long requestorId, long instanceId, long ranFunctionId, long actionId, long seqNum, uint8_t *ind_header_buf, int header_length, uint8_t *ind_message_buf, int message_length) {
  encoding::generate_e2apv1_indication_request_parameterized(e2ap_pdu, indicationType, requestorId, instanceId, ranFunctionId, actionId, seqNum, ind_header_buf, header_length, ind_message_buf, message_length);

}

int E2Sim::run_loop(const char *server_addr, int server_port){
  logger_force(LOGGER_INFO, "Start E2 Agent (E2 Simulator)");

  char *addr = (char *)server_addr;
  if(addr == NULL) {
    addr = (char *)DEFAULT_SCTP_IP;
  }
  if(server_port < 1 || server_port > 65535) {
    logger_warn("Invalid port number (%d). Valid values are between 1 and 65535. Using default port (%d)",
                                                                              server_port, E2AP_SCTP_PORT);
    server_port = E2AP_SCTP_PORT;
  }

  // ifstream simfile;
  // string line;

  // simfile.open("simulation.txt", ios::in);

  // if (simfile.is_open()) {

  //   while (getline(simfile, line)) {
  //     cout << line << "\n";
  //   }

  //   simfile.close();

  // }

  bool xmlenc = false;

  // options_t ops = read_input_options(argc, argv);

  logger_trace("After reading input options");

  //E2 Agent will automatically restart upon sctp disconnection
  //  int server_fd = sctp_start_server(ops.server_ip, ops.server_port);

  client_fd = sctp_start_client(addr, server_port);

  logger_trace("After starting SCTP client");

  E2AP_PDU_t* pdu_setup = (E2AP_PDU_t*)calloc(1,sizeof(E2AP_PDU));

  std::vector<encoding::ran_func_info> all_funcs;
  // RANfunctionOID_t *ranFunctionOIDe = (RANfunctionOID_t*)calloc(1,sizeof(RANfunctionOID_t));
  // uint8_t *buf = (uint8_t*)"OID123";
  // ranFunctionOIDe->buf = (uint8_t*)calloc(1,strlen((char*)buf)+1);
  // memcpy(ranFunctionOIDe->buf, buf, strlen((char*)buf)+1);
  // ranFunctionOIDe->size = strlen((char*)buf);

  //Loop through RAN function definitions that are registered

  for (std::pair<long, encoded_ran_function_t *> elem : ran_functions_registered) {
   logger_trace("looping through ran func");
    encoding::ran_func_info next_func;

    next_func.ranFunctionId = elem.first;
    next_func.ranFunctionDesc = &elem.second->ran_function_ostr;
    next_func.ranFunctionRev = (long)2;
    next_func.ranFunctionOId = &elem.second->oid;

    all_funcs.push_back(next_func);
  }

  logger_trace("about to call setup request encode");
  generate_e2apv1_setup_request_parameterized(pdu_setup, all_funcs);

  logger_trace("After generating e2setup req");

  if (LOGGER_LEVEL >= LOGGER_DEBUG) {
    xer_fprint(stderr, &asn_DEF_E2AP_PDU, pdu_setup);
  }

  logger_trace("After XER Encoding");

  auto buffer_size = MAX_SCTP_BUFFER;
  unsigned char buffer[MAX_SCTP_BUFFER];

  sctp_buffer_t data;

  char error_buf[300] = {0, };
  size_t errlen = 0;

  int ret = asn_check_constraints(&asn_DEF_E2AP_PDU, pdu_setup, error_buf, &errlen);
  if (ret != 0) {
    logger_error("E2AP_PDU check constraints failed. error length = %ld, error buf %s", errlen, error_buf);
  }

  auto er = asn_encode_to_buffer(NULL, ATS_ALIGNED_BASIC_PER, &asn_DEF_E2AP_PDU, pdu_setup, buffer, buffer_size);

  data.len = er.encoded;

  logger_debug("er encded is %ld", er.encoded);

  memcpy(data.buffer, buffer, er.encoded);

  if(sctp_send_data(client_fd, data, NULL) > 0) {
    logger_info("[SCTP] Sent E2-SETUP-REQUEST");
  } else {
    logger_error("[SCTP] Unable to send E2-SETUP-REQUEST to peer");
  }

  sctp_buffer_t recv_buf;

  logger_info("[SCTP] Waiting for SCTP data");

  struct timespec ts; // timestamp of the received message

  while(1) //constantly looking for data on SCTP interface
  {
    if(sctp_receive_data(client_fd, recv_buf, &ts) <= 0)
      break;

    logger_debug("[SCTP] Received new data of size %d", recv_buf.len);

    e2ap_handle_sctp_data(client_fd, recv_buf, xmlenc, this, &ts);
    if (xmlenc) xmlenc = false;
  }

  return 0;
}
