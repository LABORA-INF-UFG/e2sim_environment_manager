/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm-rc-v01.02.asn"
 * 	`asn1c -fcompound-names -findirect-choice -fincludes-quoted -fno-include-deps -no-gen-example`
 */

#include "E2SM-RC-ControlHeader-Format2.h"

#include "UEID.h"
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_ric_ControlDecision_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_ric_ControlDecision_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_ric_ControlDecision_value2enum_3[] = {
	{ 0,	6,	"accept" },
	{ 1,	6,	"reject" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_ric_ControlDecision_enum2value_3[] = {
	0,	/* accept(0) */
	1	/* reject(1) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_ric_ControlDecision_specs_3 = {
	asn_MAP_ric_ControlDecision_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_ric_ControlDecision_enum2value_3,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_ric_ControlDecision_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ric_ControlDecision_3 = {
	"ric-ControlDecision",
	"ric-ControlDecision",
	&asn_OP_NativeEnumerated,
	asn_DEF_ric_ControlDecision_tags_3,
	sizeof(asn_DEF_ric_ControlDecision_tags_3)
		/sizeof(asn_DEF_ric_ControlDecision_tags_3[0]) - 1, /* 1 */
	asn_DEF_ric_ControlDecision_tags_3,	/* Same as above */
	sizeof(asn_DEF_ric_ControlDecision_tags_3)
		/sizeof(asn_DEF_ric_ControlDecision_tags_3[0]), /* 2 */
	{ &asn_OER_type_ric_ControlDecision_constr_3, &asn_PER_type_ric_ControlDecision_constr_3, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ric_ControlDecision_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_E2SM_RC_ControlHeader_Format2_1[] = {
	{ ATF_POINTER, 2, offsetof(struct E2SM_RC_ControlHeader_Format2, ueID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_UEID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ueID"
		},
	{ ATF_POINTER, 1, offsetof(struct E2SM_RC_ControlHeader_Format2, ric_ControlDecision),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ric_ControlDecision_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ric-ControlDecision"
		},
};
static const int asn_MAP_E2SM_RC_ControlHeader_Format2_oms_1[] = { 0, 1 };
static const ber_tlv_tag_t asn_DEF_E2SM_RC_ControlHeader_Format2_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2SM_RC_ControlHeader_Format2_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ueID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ric-ControlDecision */
};
asn_SEQUENCE_specifics_t asn_SPC_E2SM_RC_ControlHeader_Format2_specs_1 = {
	sizeof(struct E2SM_RC_ControlHeader_Format2),
	offsetof(struct E2SM_RC_ControlHeader_Format2, _asn_ctx),
	asn_MAP_E2SM_RC_ControlHeader_Format2_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_E2SM_RC_ControlHeader_Format2_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2SM_RC_ControlHeader_Format2 = {
	"E2SM-RC-ControlHeader-Format2",
	"E2SM-RC-ControlHeader-Format2",
	&asn_OP_SEQUENCE,
	asn_DEF_E2SM_RC_ControlHeader_Format2_tags_1,
	sizeof(asn_DEF_E2SM_RC_ControlHeader_Format2_tags_1)
		/sizeof(asn_DEF_E2SM_RC_ControlHeader_Format2_tags_1[0]), /* 1 */
	asn_DEF_E2SM_RC_ControlHeader_Format2_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2SM_RC_ControlHeader_Format2_tags_1)
		/sizeof(asn_DEF_E2SM_RC_ControlHeader_Format2_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_E2SM_RC_ControlHeader_Format2_1,
	2,	/* Elements count */
	&asn_SPC_E2SM_RC_ControlHeader_Format2_specs_1	/* Additional specs */
};

