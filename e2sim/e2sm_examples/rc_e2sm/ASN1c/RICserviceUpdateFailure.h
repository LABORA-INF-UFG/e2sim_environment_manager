/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e2ap-v02.01.asn"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -no-gen-example`
 */

#ifndef	_RICserviceUpdateFailure_H_
#define	_RICserviceUpdateFailure_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ProtocolIE-Container.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RICserviceUpdateFailure */
typedef struct RICserviceUpdateFailure {
	ProtocolIE_Container_1993P25_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RICserviceUpdateFailure_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RICserviceUpdateFailure;
extern asn_SEQUENCE_specifics_t asn_SPC_RICserviceUpdateFailure_specs_1;
extern asn_TYPE_member_t asn_MBR_RICserviceUpdateFailure_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _RICserviceUpdateFailure_H_ */
#include "asn_internal.h"
