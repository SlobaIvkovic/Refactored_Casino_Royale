#include "neslib.h"
#include "include/hardware_setup.h"
#include "include/load_screens.h"

// for (i = 0; in[i]; i++)  to the end of the array

//extern char music1[];

#define rtassert(expr, msg)\
{\
	char static_assertion_failed__##msg[(expr)?1:-1];\
}\

#pragma code-name(push, "CODE2")

#pragma code-name(pop)

#define AD 0x210B

// Main is in CODE, aka RAM here. Could put it elsewhere too
void main() {
	
const unsigned int n = 0x210B;
// assert type, check its size and if it is negative
// check #define values if they are signed
// hex defines should never be signed, defined constant number should be casted to unsigned char
	rtassert((sizeof(char)==1), INVALID_VARIABLE_SIZE);
	// The BG is off by one pixel on SNES, compensate by scrolling
	
	LoadTitleScreen();
	
/*
	//spc_stereo(1);
	spc_sfxpan = 128;
	spc_sfxvol = 255;
	spc_sfxchan = 7;
	sfx_play(0);
	sfx_play(30);
	music_play(0x82, music1);
*/

	while (1) {
	
		
	}
}
