#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K00, K01, K02, K03, K04, K05, K06, \
	K10, K11, K12, K13, K14, K15, K16, \
	K20, K21, K22, K23, K24, K25, K26, \
	K57, K58, K59,  K33, K34, K35, K36, \
	K60, K41, K61,  K43, K44, K45, K46, \
	K50, K51, K52, K53, K54, K55, K56  \
) { \
	{ K00,   K01,   K02,   K03,   K04,   K05,   K06 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16 }, \
	{ K20,   K21,   K22,   K23,   K24,   K25,   K26 }, \
	{ K57, K58, K59, K33,   K34,   K35,   K36 }, \
	{ K60, K41,   K61, K43,   K44,   K45,   K46 }, \
	{ K50,   K51,   K52,   K53,   K54,   K55,   K56 }  \
}

#endif