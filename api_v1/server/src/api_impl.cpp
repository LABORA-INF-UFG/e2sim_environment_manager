#include <memory>
#include <optional>
#include <string>

// Yay pistache
#ifdef DEBUG
#undef DEBUG
#endif

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include "TestingApi.h"
#include "ManagementApi.h"
#include "MonitoringApi.h"

#include "_endpoints_get_200_response.h"
#include "Ue_descriptor.h"
#include "_UE_get_200_response.h"
#include "_UE__iMSI__anr_put_request.h"
#include "_UE__iMSI__flow_put_request.h"

#include "environment_manager.h"
#include "api_impl.h"

#define PISTACHE_SERVER_THREADS 2
#define PISTACHE_SERVER_MAX_REQUEST_SIZE 32768
#define PISTACHE_SERVER_MAX_RESPONSE_SIZE 32768

static Pistache::Http::Endpoint *httpEndpoint;

using namespace org::openapitools::server::model;

void fill_anr_entry(std::map<std::string, std::shared_ptr<anr_entry>> &anr_map, const std::vector<Anr_payload> &anr_vector)
{
    anr_map.clear();

    for (auto it = anr_vector.begin(); it != anr_vector.end(); it++)
    {
        std::shared_ptr<anr_entry> entry = std::make_shared<anr_entry>();
        entry->bbu_name = it->getNodeb().getNodebId();
        entry->rsrp = it->getRSRP();
        entry->rsrq = it->getRSRQ();
        entry->sinr = it->getSINR();
        entry->cqi = it->getCQI();
        entry->bler = it->getBLER();

        std::pair<std::string, std::shared_ptr<anr_entry>> to_insert;
        to_insert.first = entry->bbu_name;
        to_insert.second = entry;

        anr_map.emplace(to_insert);
    }
}

void fill_flow_entry(flow_entry &flow_entry, const Data_plane_flow &flow_data)
{
    flow_entry.average_throughput = flow_data.getAverageThroughput();
    flow_entry.latency = flow_data.getLatency();
}

namespace org::openapitools::server::api
{
    class TestingApiImpl : public org::openapitools::server::api::TestingApi
    {
    public:
        explicit TestingApiImpl(const std::shared_ptr<Pistache::Rest::Router> &rtr);
        ~TestingApiImpl() override = default;

        void test_get(Pistache::Http::ResponseWriter &response);
        void endpoints_get(Pistache::Http::ResponseWriter &response);
    };

    TestingApiImpl::TestingApiImpl(const std::shared_ptr<Pistache::Rest::Router> &rtr)
        : TestingApi(rtr)
    { /* pass */
    }

    void TestingApiImpl::test_get(Pistache::Http::ResponseWriter &response)
    {
        response.send(Pistache::Http::Code::Ok, "Do some magic\n");
    }

    void TestingApiImpl::endpoints_get(Pistache::Http::ResponseWriter &response)
    {
        std::vector<_endpoints_get_200_response_endpoints_inner> endpoints;
        { /* blocks to limit scope and not blow up the stack */
            _endpoints_get_200_response_endpoints_inner inner;
            inner.setMethod("GET");
            inner.setUri("/test");
            inner.setDescription("Test if the API is available");
            endpoints.push_back(inner);
        }

        { /* blocks to limit scope and not blow up the stack */
            _endpoints_get_200_response_endpoints_inner inner;
            inner.setMethod("GET");
            inner.setUri("/endpoints");
            inner.setDescription("List the endpoints available");
            endpoints.push_back(inner);
        }

        { /* blocks to limit scope and not blow up the stack */
            _endpoints_get_200_response_endpoints_inner inner;
            inner.setMethod("PUT");
            inner.setUri("/UE/{iMSI}/admission");
            inner.setDescription("Associate an UE with the e2node");
            endpoints.push_back(inner);
        }

        { /* blocks to limit scope and not blow up the stack */
            _endpoints_get_200_response_endpoints_inner inner;
            inner.setMethod("DELETE");
            inner.setUri("/UE/{iMSI}/admission");
            inner.setDescription("Disassociate an UE with the e2node");
            endpoints.push_back(inner);
        }

        { /* blocks to limit scope and not blow up the stack */
            _endpoints_get_200_response_endpoints_inner inner;
            inner.setMethod("PUT");
            inner.setUri("/UE/{iMSI}/anr");
            inner.setDescription("Alter the ANR information for this UE");
            endpoints.push_back(inner);
        }

        { /* blocks to limit scope and not blow up the stack */
            _endpoints_get_200_response_endpoints_inner inner;
            inner.setMethod("PUT");
            inner.setUri("/UE/{iMSI}/flow");
            inner.setDescription("Alter the flow information for this UE");
            endpoints.push_back(inner);
        }

        { /* blocks to limit scope and not blow up the stack */
            _endpoints_get_200_response_endpoints_inner inner;
            inner.setMethod("GET");
            inner.setUri("/UE/{iMSI}/info");
            inner.setDescription("Retrieve the information for an UE");
            endpoints.push_back(inner);
        }

        { /* blocks to limit scope and not blow up the stack */
            _endpoints_get_200_response_endpoints_inner inner;
            inner.setMethod("GET");
            inner.setUri("/UE");
            inner.setDescription("List the UEs associated with this e2node");
            endpoints.push_back(inner);
        }

        _endpoints_get_200_response response_data;
        response_data.setEndpoints(endpoints);

        nlohmann::json j;
        to_json(j, response_data);

        response.send(Pistache::Http::Code::Ok, to_string(j));
    }

    class ManagementApiImpl : public org::openapitools::server::api::ManagementApi
    {
    public:
        explicit ManagementApiImpl(const std::shared_ptr<Pistache::Rest::Router> &rtr, std::shared_ptr<EnvironmentManagerObserver> observer);
        ~ManagementApiImpl() override = default;

        void u_eimsi_admission_delete(const std::string &iMSI, Pistache::Http::ResponseWriter &response);
        void u_eimsi_admission_put(const std::string &iMSI, const Ue_descriptor &ueDescriptor, Pistache::Http::ResponseWriter &response);
        void u_eimsi_anr_put(const std::string &iMSI, const _UE__iMSI__anr_put_request &uEIMSIAnrPutRequest, Pistache::Http::ResponseWriter &response);
        void u_eimsi_flow_put(const std::string &iMSI, const _UE__iMSI__flow_put_request &uEIMSIFlowPutRequest, Pistache::Http::ResponseWriter &response);

    protected:
        std::shared_ptr<EnvironmentManagerObserver> observer;
    };

    ManagementApiImpl::ManagementApiImpl(const std::shared_ptr<Pistache::Rest::Router> &rtr, std::shared_ptr<EnvironmentManagerObserver> observer)
        : ManagementApi(rtr), observer(observer)
    { /* pass */
    }
    void ManagementApiImpl::u_eimsi_admission_delete(const std::string &iMSI, Pistache::Http::ResponseWriter &response)
    {
        //logger_force(LOGGER_INFO, "UE %s disconnected", iMSI.c_str());
        auto ue_it = ue_map.find(iMSI);
        if (ue_it == ue_map.end()) {
            response.send(Pistache::Http::Code::Not_Found);
            return;
        }

        observer->disassociationRequest(ue_it->second);
        ue_map.erase(iMSI);
        response.send(Pistache::Http::Code::Ok);
    }

    void ManagementApiImpl::u_eimsi_admission_put(const std::string &iMSI, const Ue_descriptor &ueDescriptor, Pistache::Http::ResponseWriter &response)
    {
        std::pair<std::string, std::shared_ptr<ue_data>> to_insert;
        to_insert.first = iMSI;

        std::shared_ptr<ue_data> data = std::make_shared<ue_data>();
        data->imsi = iMSI;
        data->endpoint = ueDescriptor.getEndpoint();

        fill_flow_entry(data->flow, ueDescriptor.getDataPlaneFlow());

        std::vector<Anr_payload> anr_vector = ueDescriptor.getAnrPayload();
        fill_anr_entry(data->anr, anr_vector);
        to_insert.second = data;

        observer->associationRequest(data);

        ue_map.emplace(to_insert);

        //logger_force(LOGGER_INFO, "UE %s admission accepted", iMSI.c_str());

        response.send(Pistache::Http::Code::Ok);
    }

    void ManagementApiImpl::u_eimsi_anr_put(const std::string &iMSI, const _UE__iMSI__anr_put_request &uEIMSIAnrPutRequest, Pistache::Http::ResponseWriter &response)
    {
        auto ue = ue_map.find(iMSI);
        if (ue == ue_map.end())
        {
            response.send(Pistache::Http::Code::Not_Found);
            return;
        }

        fill_anr_entry(ue->second->anr, uEIMSIAnrPutRequest.getNodebList());

        observer->anrUpdate(ue->first, ue->second->anr);

        //logger_force(LOGGER_INFO, "ANR data for UE %s changed",
        //             ue->second->imsi.c_str);

        response.send(Pistache::Http::Code::Ok);
    }

    void ManagementApiImpl::u_eimsi_flow_put(const std::string &iMSI, const _UE__iMSI__flow_put_request &uEIMSIFlowPutRequest, Pistache::Http::ResponseWriter &response)
    {
        auto ue = ue_map.find(iMSI);
        if (ue == ue_map.end())
        {
            response.send(Pistache::Http::Code::Not_Found);
            return;
        }

        fill_flow_entry(ue->second->flow, uEIMSIFlowPutRequest.getFlow());

        //logger_force(LOGGER_INFO, "Flow parameters for UE %s changed",
        //             ue->second->imsi.c_str);

        observer->flowUpdate(ue->first, ue->second->flow);

        response.send(Pistache::Http::Code::Ok);
    }

    class MonitoringApiImpl : public org::openapitools::server::api::MonitoringApi
    {
    public:
        explicit MonitoringApiImpl(const std::shared_ptr<Pistache::Rest::Router> &rtr);
        ~MonitoringApiImpl() override = default;

        void u_e_get(Pistache::Http::ResponseWriter &response);
        void u_eimsi_info_get(const std::string &iMSI, Pistache::Http::ResponseWriter &response);
    };

    MonitoringApiImpl::MonitoringApiImpl(const std::shared_ptr<Pistache::Rest::Router> &rtr)
        : MonitoringApi(rtr)
    { /* pass */
    }

    void MonitoringApiImpl::u_e_get(Pistache::Http::ResponseWriter &response)
    {
        std::vector<std::string> iMSIs;
        for (auto it = ue_map.begin(); it != ue_map.end(); it++)
        {
            iMSIs.push_back(it->first);
        }

        _UE_get_200_response response_data;
        response_data.setUeList(iMSIs);

        nlohmann::json j;
        to_json(j, response_data);

        response.send(Pistache::Http::Code::Ok, to_string(j));
    }

    void MonitoringApiImpl::u_eimsi_info_get(const std::string &iMSI, Pistache::Http::ResponseWriter &response)
    {
        auto it = ue_map.find(iMSI);
        if (it == ue_map.end())
        {
            response.send(Pistache::Http::Code::Not_Found);
            return;
        }

        std::shared_ptr<ue_data> ue = it->second;

        Data_plane_flow flow;
        flow.setAverageThroughput(ue->flow.average_throughput);
        flow.setLatency(ue->flow.latency);

        std::vector<Anr_payload> anrs;
        for (auto it = ue->anr.begin(); it != ue->anr.end(); it++)
        {
            std::shared_ptr<anr_entry> entry = it->second;
            Nodeb_descriptor nodeb;
            nodeb.setNodebId(entry->bbu_name);

            Anr_payload payload;
            payload.setNodeb(nodeb);
            payload.setRSRP(entry->rsrp);
            payload.setRSRQ(entry->rsrq);
            payload.setSINR(entry->sinr);
            payload.setCQI(entry->cqi);
            payload.setBLER(entry->bler);

            anrs.push_back(payload);
        }

        Ue_descriptor descriptor;
        descriptor.setDataPlaneFlow(flow);
        descriptor.setAnrPayload(anrs);
        descriptor.setEndpoint(ue->endpoint);

        nlohmann::json j;
        to_json(j, descriptor);

        response.send(Pistache::Http::Code::Ok, to_string(j));
    }

} // namespace org::openapitools::server::api

using namespace org::openapitools::server::api;

void run_api(std::shared_ptr<api_config> config)
{
    // logger_info("Starting environment manager on port %d", port);
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(config->port));

    httpEndpoint = new Pistache::Http::Endpoint((addr));
    auto router = std::make_shared<Pistache::Rest::Router>();

    auto opts = Pistache::Http::Endpoint::options()
                    .threads(PISTACHE_SERVER_THREADS);
    opts.flags(Pistache::Tcp::Options::ReuseAddr);
    opts.maxRequestSize(PISTACHE_SERVER_MAX_REQUEST_SIZE);
    opts.maxResponseSize(PISTACHE_SERVER_MAX_RESPONSE_SIZE);
    httpEndpoint->init(opts);
    auto apiImpls = std::vector<std::shared_ptr<ApiBase>>();

    apiImpls.push_back(std::make_shared<ManagementApiImpl>(router, config->observer));
    apiImpls.push_back(std::make_shared<TestingApiImpl>(router));
    apiImpls.push_back(std::make_shared<MonitoringApiImpl>(router));

    for (auto api : apiImpls)
    {
        api->init();
    }

    httpEndpoint->setHandler(router->handler());
    // logger_info("About to  call serve on enivronment manager");
    httpEndpoint->serve();
}

void stop_api() {
    httpEndpoint->shutdown();
}
