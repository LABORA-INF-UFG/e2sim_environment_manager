/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-CommonDataTypes"
 * 	found in "e2ap-v02.01.asn"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -no-gen-example`
 */

#ifndef	_ProtocolIE_ID_H_
#define	_ProtocolIE_ID_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ProtocolIE-ID */
typedef long	 ProtocolIE_ID_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_ProtocolIE_ID_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_ID;
asn_struct_free_f ProtocolIE_ID_free;
asn_struct_print_f ProtocolIE_ID_print;
asn_constr_check_f ProtocolIE_ID_constraint;
ber_type_decoder_f ProtocolIE_ID_decode_ber;
der_type_encoder_f ProtocolIE_ID_encode_der;
xer_type_decoder_f ProtocolIE_ID_decode_xer;
xer_type_encoder_f ProtocolIE_ID_encode_xer;
oer_type_decoder_f ProtocolIE_ID_decode_oer;
oer_type_encoder_f ProtocolIE_ID_encode_oer;
per_type_decoder_f ProtocolIE_ID_decode_uper;
per_type_encoder_f ProtocolIE_ID_encode_uper;
per_type_decoder_f ProtocolIE_ID_decode_aper;
per_type_encoder_f ProtocolIE_ID_encode_aper;
#define ProtocolIE_ID_id_Cause	((ProtocolIE_ID_t)1)
#define ProtocolIE_ID_id_CriticalityDiagnostics	((ProtocolIE_ID_t)2)
#define ProtocolIE_ID_id_GlobalE2node_ID	((ProtocolIE_ID_t)3)
#define ProtocolIE_ID_id_GlobalRIC_ID	((ProtocolIE_ID_t)4)
#define ProtocolIE_ID_id_RANfunctionID	((ProtocolIE_ID_t)5)
#define ProtocolIE_ID_id_RANfunctionID_Item	((ProtocolIE_ID_t)6)
#define ProtocolIE_ID_id_RANfunctionIEcause_Item	((ProtocolIE_ID_t)7)
#define ProtocolIE_ID_id_RANfunction_Item	((ProtocolIE_ID_t)8)
#define ProtocolIE_ID_id_RANfunctionsAccepted	((ProtocolIE_ID_t)9)
#define ProtocolIE_ID_id_RANfunctionsAdded	((ProtocolIE_ID_t)10)
#define ProtocolIE_ID_id_RANfunctionsDeleted	((ProtocolIE_ID_t)11)
#define ProtocolIE_ID_id_RANfunctionsModified	((ProtocolIE_ID_t)12)
#define ProtocolIE_ID_id_RANfunctionsRejected	((ProtocolIE_ID_t)13)
#define ProtocolIE_ID_id_RICaction_Admitted_Item	((ProtocolIE_ID_t)14)
#define ProtocolIE_ID_id_RICactionID	((ProtocolIE_ID_t)15)
#define ProtocolIE_ID_id_RICaction_NotAdmitted_Item	((ProtocolIE_ID_t)16)
#define ProtocolIE_ID_id_RICactions_Admitted	((ProtocolIE_ID_t)17)
#define ProtocolIE_ID_id_RICactions_NotAdmitted	((ProtocolIE_ID_t)18)
#define ProtocolIE_ID_id_RICaction_ToBeSetup_Item	((ProtocolIE_ID_t)19)
#define ProtocolIE_ID_id_RICcallProcessID	((ProtocolIE_ID_t)20)
#define ProtocolIE_ID_id_RICcontrolAckRequest	((ProtocolIE_ID_t)21)
#define ProtocolIE_ID_id_RICcontrolHeader	((ProtocolIE_ID_t)22)
#define ProtocolIE_ID_id_RICcontrolMessage	((ProtocolIE_ID_t)23)
#define ProtocolIE_ID_id_RICcontrolStatus	((ProtocolIE_ID_t)24)
#define ProtocolIE_ID_id_RICindicationHeader	((ProtocolIE_ID_t)25)
#define ProtocolIE_ID_id_RICindicationMessage	((ProtocolIE_ID_t)26)
#define ProtocolIE_ID_id_RICindicationSN	((ProtocolIE_ID_t)27)
#define ProtocolIE_ID_id_RICindicationType	((ProtocolIE_ID_t)28)
#define ProtocolIE_ID_id_RICrequestID	((ProtocolIE_ID_t)29)
#define ProtocolIE_ID_id_RICsubscriptionDetails	((ProtocolIE_ID_t)30)
#define ProtocolIE_ID_id_TimeToWait	((ProtocolIE_ID_t)31)
#define ProtocolIE_ID_id_RICcontrolOutcome	((ProtocolIE_ID_t)32)
#define ProtocolIE_ID_id_E2nodeComponentConfigUpdate	((ProtocolIE_ID_t)33)
#define ProtocolIE_ID_id_E2nodeComponentConfigUpdate_Item	((ProtocolIE_ID_t)34)
#define ProtocolIE_ID_id_E2nodeComponentConfigUpdateAck	((ProtocolIE_ID_t)35)
#define ProtocolIE_ID_id_E2nodeComponentConfigUpdateAck_Item	((ProtocolIE_ID_t)36)
#define ProtocolIE_ID_id_E2connectionSetup	((ProtocolIE_ID_t)39)
#define ProtocolIE_ID_id_E2connectionSetupFailed	((ProtocolIE_ID_t)40)
#define ProtocolIE_ID_id_E2connectionSetupFailed_Item	((ProtocolIE_ID_t)41)
#define ProtocolIE_ID_id_E2connectionFailed_Item	((ProtocolIE_ID_t)42)
#define ProtocolIE_ID_id_E2connectionUpdate_Item	((ProtocolIE_ID_t)43)
#define ProtocolIE_ID_id_E2connectionUpdateAdd	((ProtocolIE_ID_t)44)
#define ProtocolIE_ID_id_E2connectionUpdateModify	((ProtocolIE_ID_t)45)
#define ProtocolIE_ID_id_E2connectionUpdateRemove	((ProtocolIE_ID_t)46)
#define ProtocolIE_ID_id_E2connectionUpdateRemove_Item	((ProtocolIE_ID_t)47)
#define ProtocolIE_ID_id_TNLinformation	((ProtocolIE_ID_t)48)
#define ProtocolIE_ID_id_TransactionID	((ProtocolIE_ID_t)49)
#define ProtocolIE_ID_id_E2nodeComponentConfigAddition	((ProtocolIE_ID_t)50)
#define ProtocolIE_ID_id_E2nodeComponentConfigAddition_Item	((ProtocolIE_ID_t)51)
#define ProtocolIE_ID_id_E2nodeComponentConfigAdditionAck	((ProtocolIE_ID_t)52)
#define ProtocolIE_ID_id_E2nodeComponentConfigAdditionAck_Item	((ProtocolIE_ID_t)53)
#define ProtocolIE_ID_id_E2nodeComponentConfigRemoval	((ProtocolIE_ID_t)54)
#define ProtocolIE_ID_id_E2nodeComponentConfigRemoval_Item	((ProtocolIE_ID_t)55)
#define ProtocolIE_ID_id_E2nodeComponentConfigRemovalAck	((ProtocolIE_ID_t)56)
#define ProtocolIE_ID_id_E2nodeComponentConfigRemovalAck_Item	((ProtocolIE_ID_t)57)
#define ProtocolIE_ID_id_E2nodeTNLassociationRemoval	((ProtocolIE_ID_t)58)
#define ProtocolIE_ID_id_E2nodeTNLassociationRemoval_Item	((ProtocolIE_ID_t)59)
#define ProtocolIE_ID_id_RICsubscriptionToBeRemoved	((ProtocolIE_ID_t)60)
#define ProtocolIE_ID_id_RICsubscription_withCause_Item	((ProtocolIE_ID_t)61)

#ifdef __cplusplus
}
#endif

#endif	/* _ProtocolIE_ID_H_ */
#include "asn_internal.h"
