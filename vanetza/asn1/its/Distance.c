/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "IS_TS103301/ISO_TS_19321.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -D /home/rieblr/work/car2x/vanetza/vanetza/asn1/its`
 */

#include "Distance.h"

static int
memb_value_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 16384)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_unit_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if(((value >= 2 && value <= 4) || (value >= 6 && value <= 8))) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_memb_value_constr_2 CC_NOTUSED = {
	{ 2, 1 }	/* (1..16384) */,
	-1};
static asn_per_constraints_t asn_PER_memb_value_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 14,  14,  1,  16384 }	/* (1..16384) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_unit_constr_3 CC_NOTUSED = {
	{ 1, 1 }	/* (2..8) */,
	-1};
static asn_per_constraints_t asn_PER_memb_unit_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  2,  8 }	/* (2..8) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_Distance_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Distance, value),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_value_constr_2, &asn_PER_memb_value_constr_2,  memb_value_constraint_1 },
		0, 0, /* No default value */
		"value"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Distance, unit),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RSCUnit,
		0,
		{ &asn_OER_memb_unit_constr_3, &asn_PER_memb_unit_constr_3,  memb_unit_constraint_1 },
		0, 0, /* No default value */
		"unit"
		},
};
static const ber_tlv_tag_t asn_DEF_Distance_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Distance_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* value */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* unit */
};
asn_SEQUENCE_specifics_t asn_SPC_Distance_specs_1 = {
	sizeof(struct Distance),
	offsetof(struct Distance, _asn_ctx),
	asn_MAP_Distance_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Distance = {
	"Distance",
	"Distance",
	&asn_OP_SEQUENCE,
	asn_DEF_Distance_tags_1,
	sizeof(asn_DEF_Distance_tags_1)
		/sizeof(asn_DEF_Distance_tags_1[0]), /* 1 */
	asn_DEF_Distance_tags_1,	/* Same as above */
	sizeof(asn_DEF_Distance_tags_1)
		/sizeof(asn_DEF_Distance_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Distance_1,
	2,	/* Elements count */
	&asn_SPC_Distance_specs_1	/* Additional specs */
};
