#include "neslib.h"
#include "include/load_screens.h"
#include "include/palettes.h"
 
void LoadTitleScreen()
{
	scroll(0, 255);
	
	ppu_off();
	SET_BG_MODE(SMALL_TILES, SMALL_TILES, SMALL_TILES, SMALL_TILES, BG3_NOT_ON_TOP, MODE_3);
	SET_BG_CHARSET_ADDRESS(1, 0x1000);
	SET_BG_CHARMAP(1, 0x0000);
	
	SET_BG_CHARSET_ADDRESS(2, 0x3000);
	SET_BG_CHARMAP(2, 0x0400);
	
	vram_adr(0x1000);
	vram_write_bank(0x8C, (char *) 0x8000, 21472);
	
	vram_write_bank(0x8D, (char *) 0x8000, 21472);
	// upload charmap
	vram_adr(0x0000);
 	vram_write_bank(0x8C, (char *) 0x8000 + 21472, 1972);
	
	pal_clear();
	pal_all(0, title_palette);
	pal_all(1, &title_palette[16]);
	
	ppu_wait_nmi();
	ppu_on_all();
}
