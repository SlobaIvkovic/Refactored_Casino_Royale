#include <assert.h>


#define BIG_TILES   1
#define SMALL_TILES 0

#define BG3_ON_TOP     1
#define BG3_NOT_ON_TOP 0

#define MODE_0 0
#define MODE_3 3

// Explain mixing between C and assembly problems

#define SET_BG_MODE(BG4_SIZE, BG3_SIZE, BG2_SIZE, BG1_SIZE, BG3_PRIO, BG_MODE)\
{\
	asm("lda #%b", (unsigned char) (BG4_SIZE << 7 | BG3_SIZE << 6 | BG2_SIZE << 5 | BG1_SIZE << 4 | BG3_PRIO << 3 | BG_MODE));\
	asm("sta $2105");\
}\

#define PLACE_AT_BIT_GROUP(a) 
#define SHIFT_BG_BITS (a) ((a-1) * 4)

#define SET_BG_CHARSET_ADDRESS(BG, ADDR)\
{\
	asm("lda %w", (unsigned short)0x210B);\
	asm("ora #%b", (unsigned char)((ADDR/0x1000) << ((BG - 1) * 4)));\
	asm("sta %w", ((unsigned short)((0x210B) + (BG > 2))));\
}\


// AND HEIGHT ADD
#define SET_BG_CHARMAP(BG, ADDR)\
{\
	asm("lda #%b", (unsigned char)((ADDR/0x400) << 2));\
	asm("sta %w", (unsigned short)(0x2106 + BG));\
}\


