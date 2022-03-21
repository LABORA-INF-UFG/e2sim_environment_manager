/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e2ap-v2.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-example`
 */

#ifndef	_RICaction_ToBeSetup_Item_H_
#define	_RICaction_ToBeSetup_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RICactionID.h"
#include "RICactionType.h"
#include "RICactionDefinition.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RICsubsequentAction;

/* RICaction-ToBeSetup-Item */
typedef struct RICaction_ToBeSetup_Item {
	RICactionID_t	 ricActionID;
	RICactionType_t	 ricActionType;
	RICactionDefinition_t	*ricActionDefinition;	/* OPTIONAL */
	struct RICsubsequentAction	*ricSubsequentAction;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RICaction_ToBeSetup_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RICaction_ToBeSetup_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _RICaction_ToBeSetup_Item_H_ */
#include "asn_internal.h"
