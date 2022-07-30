/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm-v02.01.asn"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -no-gen-example`
 */

#include "Interface-MessageID.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_messageType_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_messageType_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_messageType_value2enum_3[] = {
	{ 0,	17,	"initiatingMessage" },
	{ 1,	17,	"successfulOutcome" },
	{ 2,	19,	"unsuccessfulOutcome" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_messageType_enum2value_3[] = {
	0,	/* initiatingMessage(0) */
	1,	/* successfulOutcome(1) */
	2	/* unsuccessfulOutcome(2) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_messageType_specs_3 = {
	asn_MAP_messageType_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_messageType_enum2value_3,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_messageType_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_messageType_3 = {
	"messageType",
	"messageType",
	&asn_OP_NativeEnumerated,
	asn_DEF_messageType_tags_3,
	sizeof(asn_DEF_messageType_tags_3)
		/sizeof(asn_DEF_messageType_tags_3[0]) - 1, /* 1 */
	asn_DEF_messageType_tags_3,	/* Same as above */
	sizeof(asn_DEF_messageType_tags_3)
		/sizeof(asn_DEF_messageType_tags_3[0]), /* 2 */
	{ &asn_OER_type_messageType_constr_3, &asn_PER_type_messageType_constr_3, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_messageType_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_Interface_MessageID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Interface_MessageID, interfaceProcedureID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"interfaceProcedureID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Interface_MessageID, messageType),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_messageType_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"messageType"
		},
};
static const ber_tlv_tag_t asn_DEF_Interface_MessageID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Interface_MessageID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* interfaceProcedureID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* messageType */
};
asn_SEQUENCE_specifics_t asn_SPC_Interface_MessageID_specs_1 = {
	sizeof(struct Interface_MessageID),
	offsetof(struct Interface_MessageID, _asn_ctx),
	asn_MAP_Interface_MessageID_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Interface_MessageID = {
	"Interface-MessageID",
	"Interface-MessageID",
	&asn_OP_SEQUENCE,
	asn_DEF_Interface_MessageID_tags_1,
	sizeof(asn_DEF_Interface_MessageID_tags_1)
		/sizeof(asn_DEF_Interface_MessageID_tags_1[0]), /* 1 */
	asn_DEF_Interface_MessageID_tags_1,	/* Same as above */
	sizeof(asn_DEF_Interface_MessageID_tags_1)
		/sizeof(asn_DEF_Interface_MessageID_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Interface_MessageID_1,
	2,	/* Elements count */
	&asn_SPC_Interface_MessageID_specs_1	/* Additional specs */
};

