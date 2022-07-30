/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e2ap-v02.01.asn1"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-example -no-gen-OER`
 */

#ifndef	_E2connectionUpdate_Item_H_
#define	_E2connectionUpdate_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "TNLinformation.h"
#include "TNLusage.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2connectionUpdate-Item */
typedef struct E2connectionUpdate_Item {
	TNLinformation_t	 tnlInformation;
	TNLusage_t	 tnlUsage;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2connectionUpdate_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2connectionUpdate_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _E2connectionUpdate_Item_H_ */
#include "asn_internal.h"
