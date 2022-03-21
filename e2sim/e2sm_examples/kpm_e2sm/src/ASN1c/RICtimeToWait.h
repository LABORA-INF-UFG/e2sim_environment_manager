/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "e2ap-v2.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-example`
 */

#ifndef	_RICtimeToWait_H_
#define	_RICtimeToWait_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RICtimeToWait {
	RICtimeToWait_w1ms	= 0,
	RICtimeToWait_w2ms	= 1,
	RICtimeToWait_w5ms	= 2,
	RICtimeToWait_w10ms	= 3,
	RICtimeToWait_w20ms	= 4,
	RICtimeToWait_w30ms	= 5,
	RICtimeToWait_w40ms	= 6,
	RICtimeToWait_w50ms	= 7,
	RICtimeToWait_w100ms	= 8,
	RICtimeToWait_w200ms	= 9,
	RICtimeToWait_w500ms	= 10,
	RICtimeToWait_w1s	= 11,
	RICtimeToWait_w2s	= 12,
	RICtimeToWait_w5s	= 13,
	RICtimeToWait_w10s	= 14,
	RICtimeToWait_w20s	= 15,
	RICtimeToWait_w60s	= 16
	/*
	 * Enumeration is extensible
	 */
} e_RICtimeToWait;

/* RICtimeToWait */
typedef long	 RICtimeToWait_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_RICtimeToWait_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_RICtimeToWait;
extern const asn_INTEGER_specifics_t asn_SPC_RICtimeToWait_specs_1;
asn_struct_free_f RICtimeToWait_free;
asn_struct_print_f RICtimeToWait_print;
asn_constr_check_f RICtimeToWait_constraint;
ber_type_decoder_f RICtimeToWait_decode_ber;
der_type_encoder_f RICtimeToWait_encode_der;
xer_type_decoder_f RICtimeToWait_decode_xer;
xer_type_encoder_f RICtimeToWait_encode_xer;
oer_type_decoder_f RICtimeToWait_decode_oer;
oer_type_encoder_f RICtimeToWait_encode_oer;
per_type_decoder_f RICtimeToWait_decode_uper;
per_type_encoder_f RICtimeToWait_encode_uper;
per_type_decoder_f RICtimeToWait_decode_aper;
per_type_encoder_f RICtimeToWait_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RICtimeToWait_H_ */
#include "asn_internal.h"
