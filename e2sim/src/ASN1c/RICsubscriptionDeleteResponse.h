/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e2ap-v02.01.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-example -no-gen-OER`
 */

#ifndef	_RICsubscriptionDeleteResponse_H_
#define	_RICsubscriptionDeleteResponse_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ProtocolIE-Container.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RICsubscriptionDeleteResponse */
typedef struct RICsubscriptionDeleteResponse {
	ProtocolIE_Container_1993P4_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RICsubscriptionDeleteResponse_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RICsubscriptionDeleteResponse;
extern asn_SEQUENCE_specifics_t asn_SPC_RICsubscriptionDeleteResponse_specs_1;
extern asn_TYPE_member_t asn_MBR_RICsubscriptionDeleteResponse_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _RICsubscriptionDeleteResponse_H_ */
#include "asn_internal.h"
