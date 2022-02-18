.export spc_code, spc_code2, _bank0, _title_screen_half1, _title_screen_map, _title_screen_half2

; RODATA will contain every address first byte, hence address banks will be stored here and exported for the C code to use it
.segment "RODATA"
_bank0: .byte ^_title_screen_half1


.segment "CHR0"
_title_screen_half1:
.incbin "title_screen_bins/half.chr"                     ;21472
_title_screen_map:
.incbin "title_screen_bins/title_screen_safe.map"        ;1972


.segment "CHR1"
_title_screen_half2:
.incbin "title_screen_bins/half2.chr"                     ;21472

.segment "RODATA1"
spc_code:
.incbin "spc700.bin", 0, 32768

.segment "RODATA2"
spc_code2:
.incbin "spc700.bin", 32768

