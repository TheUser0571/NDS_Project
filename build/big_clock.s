
@{{BLOCK(big_clock)

@=======================================================================
@
@	big_clock, 80x80@4, 
@	Transparent color : 00,FF,00
@	+ palette 16 entries, not compressed
@	+ 100 tiles not compressed
@	Total size: 32 + 3200 = 3232
@
@	Time-stamp: 2019-01-07, 18:19:45
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global big_clockTiles		@ 3200 unsigned chars
big_clockTiles:
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x01111111,0x00011111,0x00001111,0x11000011,0x11100000
	.word 0x11111111,0x00011111,0x00000011,0x11000000,0x11111000,0x11111111,0x11111111,0x11111111
	.word 0x00000001,0x00000000,0x11111100,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x10000000,0x00000000,0x00111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111000,0x11000000,0x00000011,0x00011111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111110,0x11111000,0x11110000,0x11000011,0x00000111

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x01111111,0x00111111,0x00011111,0x10001111,0x11000111,0x11100011,0x11110001,0x11111000
	.word 0x11111000,0x11111110,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x00011111,0x01111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111110,0x11111100,0x11111000,0x11110001,0x11100011,0x11000111,0x10001111,0x00011111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x01111111,0x01111111,0x00111111,0x00111111,0x00011111,0x10001111,0x11001111,0x11000111
	.word 0x11111100,0x11111110,0x11111110,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x01111111
	.word 0x11111111,0x10011111,0x10001111,0x11000111,0x11100011,0x11110001,0x11111000,0x11111100
	.word 0x00111111,0x01111111,0x01111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111110,0x11111110,0x11111100,0x11111100,0x11111000,0x11110001,0x11110011,0x11100011
	.word 0x11100111,0x11100111,0x11100011,0x11110011,0x11110011,0x11110001,0x11111001,0x11111001
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111001,0x11110001,0x11100001,0x11000011,0x10000111,0x00001111,0x00011111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111110
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x01111111
	.word 0x00111111,0x00011111,0x10001111,0x11000111,0x11100011,0x11110001,0x11111000,0x11111100
	.word 0x11111110,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11100111,0x11100111,0x11000111,0x11001111,0x11001111,0x10001111,0x10011111,0x10011111

	.word 0x11111001,0x11111000,0x11111100,0x11111100,0x11111100,0x11111100,0x11111100,0x11111100
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x00111111,0x01111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111100,0x11111000,0x11110000,0x11100001,0x11000011,0x10000111,0x00001111,0x00011111
	.word 0x00111111,0x00011111,0x10001111,0x11000111,0x11100011,0x11110001,0x11111000,0x11111100
	.word 0x11111110,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x10011111,0x00011111,0x00111111,0x00111111,0x00111111,0x00111111,0x00111111,0x00111111
	.word 0x11111100,0x11111100,0x11111100,0x11111100,0x11111100,0x11111100,0x11111000,0x11111001
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x00111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111110,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x00111111,0x00111111,0x00111111,0x00111111,0x00111111,0x00111111,0x00011111,0x10011111
	.word 0x11111001,0x11111001,0x11110001,0x11110011,0x11110011,0x11100011,0x11100111,0x11100111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x10011111,0x10011111,0x10001111,0x11001111,0x11001111,0x11000111,0x11100111,0x11100111
	.word 0x11000111,0x11001111,0x10001111,0x00011111,0x00111111,0x00111111,0x01111111,0x01111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111110,0x11111110,0x11111100

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x01111111,0x01111111,0x00111111
	.word 0x11100011,0x11110011,0x11110001,0x11111000,0x11111100,0x11111100,0x11111110,0x11111110

	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111000,0x11110001,0x11100011,0x11000111,0x10001111,0x00011111,0x00111111,0x01111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111110,0x11111000
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x01111111,0x00011111

	.word 0x00011111,0x10001111,0x11000111,0x11100011,0x11110001,0x11111000,0x11111100,0x11111110
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11100000,0x11000011,0x00001111,0x00011111,0x01111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111000,0x11000000,0x00000011,0x00011111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111100,0x00000000,0x00000001
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x00111111,0x00000000,0x10000000

	.word 0x11111111,0x11111111,0x11111111,0x00011111,0x00000011,0x11000000,0x11111000,0x11111111
	.word 0x00000111,0x11000011,0x11110000,0x11111000,0x11111110,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.section .rodata
	.align	2
	.global big_clockPal		@ 32 unsigned chars
big_clockPal:
	.hword 0x0000,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(big_clock)
