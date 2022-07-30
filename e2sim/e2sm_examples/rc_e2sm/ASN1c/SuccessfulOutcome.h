/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Descriptions"
 * 	found in "e2ap-v02.01.asn"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -no-gen-example`
 */

#ifndef	_SuccessfulOutcome_H_
#define	_SuccessfulOutcome_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ProcedureCode.h"
#include "Criticality.h"
#include "ANY.h"
#include "asn_ioc.h"
#include "RICsubscriptionRequest.h"
#include "RICsubscriptionResponse.h"
#include "RICsubscriptionFailure.h"
#include "RICsubscriptionDeleteRequest.h"
#include "RICsubscriptionDeleteResponse.h"
#include "RICsubscriptionDeleteFailure.h"
#include "RICserviceUpdate.h"
#include "RICserviceUpdateAcknowledge.h"
#include "RICserviceUpdateFailure.h"
#include "RICcontrolRequest.h"
#include "RICcontrolAcknowledge.h"
#include "RICcontrolFailure.h"
#include "E2setupRequest.h"
#include "E2setupResponse.h"
#include "E2setupFailure.h"
#include "E2nodeConfigurationUpdate.h"
#include "E2nodeConfigurationUpdateAcknowledge.h"
#include "E2nodeConfigurationUpdateFailure.h"
#include "E2connectionUpdate.h"
#include "E2connectionUpdateAcknowledge.h"
#include "E2connectionUpdateFailure.h"
#include "ResetRequest.h"
#include "ResetResponse.h"
#include "E2RemovalRequest.h"
#include "E2RemovalResponse.h"
#include "E2RemovalFailure.h"
#include "RICindication.h"
#include "RICserviceQuery.h"
#include "ErrorIndication.h"
#include "RICsubscriptionDeleteRequired.h"
#include "OPEN_TYPE.h"
#include "constr_CHOICE.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SuccessfulOutcome__value_PR {
	SuccessfulOutcome__value_PR_NOTHING,	/* No components present */
	SuccessfulOutcome__value_PR_RICsubscriptionResponse,
	SuccessfulOutcome__value_PR_RICsubscriptionDeleteResponse,
	SuccessfulOutcome__value_PR_RICserviceUpdateAcknowledge,
	SuccessfulOutcome__value_PR_RICcontrolAcknowledge,
	SuccessfulOutcome__value_PR_E2setupResponse,
	SuccessfulOutcome__value_PR_E2nodeConfigurationUpdateAcknowledge,
	SuccessfulOutcome__value_PR_E2connectionUpdateAcknowledge,
	SuccessfulOutcome__value_PR_ResetResponse,
	SuccessfulOutcome__value_PR_E2RemovalResponse
} SuccessfulOutcome__value_PR;

/* SuccessfulOutcome */
typedef struct SuccessfulOutcome {
	ProcedureCode_t	 procedureCode;
	Criticality_t	 criticality;
	struct SuccessfulOutcome__value {
		SuccessfulOutcome__value_PR present;
		union SuccessfulOutcome__value_u {
			RICsubscriptionResponse_t	 RICsubscriptionResponse;
			RICsubscriptionDeleteResponse_t	 RICsubscriptionDeleteResponse;
			RICserviceUpdateAcknowledge_t	 RICserviceUpdateAcknowledge;
			RICcontrolAcknowledge_t	 RICcontrolAcknowledge;
			E2setupResponse_t	 E2setupResponse;
			E2nodeConfigurationUpdateAcknowledge_t	 E2nodeConfigurationUpdateAcknowledge;
			E2connectionUpdateAcknowledge_t	 E2connectionUpdateAcknowledge;
			ResetResponse_t	 ResetResponse;
			E2RemovalResponse_t	 E2RemovalResponse;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} value;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SuccessfulOutcome_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SuccessfulOutcome;
extern asn_SEQUENCE_specifics_t asn_SPC_SuccessfulOutcome_specs_1;
extern asn_TYPE_member_t asn_MBR_SuccessfulOutcome_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _SuccessfulOutcome_H_ */
#include "asn_internal.h"
