/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "e2ap-v02.01.asn"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -no-gen-example`
 */

#ifndef	_RICindicationMessage_H_
#define	_RICindicationMessage_H_


#include "asn_application.h"

/* Including external dependencies */
#include "OCTET_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RICindicationMessage */
typedef OCTET_STRING_t	 RICindicationMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RICindicationMessage;
asn_struct_free_f RICindicationMessage_free;
asn_struct_print_f RICindicationMessage_print;
asn_constr_check_f RICindicationMessage_constraint;
ber_type_decoder_f RICindicationMessage_decode_ber;
der_type_encoder_f RICindicationMessage_encode_der;
xer_type_decoder_f RICindicationMessage_decode_xer;
xer_type_encoder_f RICindicationMessage_encode_xer;
oer_type_decoder_f RICindicationMessage_decode_oer;
oer_type_encoder_f RICindicationMessage_encode_oer;
per_type_decoder_f RICindicationMessage_decode_uper;
per_type_encoder_f RICindicationMessage_encode_uper;
per_type_decoder_f RICindicationMessage_decode_aper;
per_type_encoder_f RICindicationMessage_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RICindicationMessage_H_ */
#include "asn_internal.h"
