/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.02.asn"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -no-gen-example`
 */

#ifndef	_E2SM_RC_IndicationMessage_Format6_Indication_Item_H_
#define	_E2SM_RC_IndicationMessage_Format6_Indication_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RIC-InsertIndication-ID.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct E2SM_RC_IndicationMessage_Format6_RANP_Item;

/* E2SM-RC-IndicationMessage-Format6-Indication-Item */
typedef struct E2SM_RC_IndicationMessage_Format6_Indication_Item {
	RIC_InsertIndication_ID_t	 ric_InsertIndication_ID;
	struct E2SM_RC_IndicationMessage_Format6_Indication_Item__ranP_InsertIndication_List {
		A_SEQUENCE_OF(struct E2SM_RC_IndicationMessage_Format6_RANP_Item) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ranP_InsertIndication_List;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_RC_IndicationMessage_Format6_Indication_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_RC_IndicationMessage_Format6_Indication_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_IndicationMessage_Format6_Indication_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_RC_IndicationMessage_Format6_Indication_Item_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_RC_IndicationMessage_Format6_Indication_Item_H_ */
#include "asn_internal.h"
