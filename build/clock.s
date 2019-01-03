
@{{BLOCK(clock)

@=======================================================================
@
@	clock, 16x16@4, 
@	Transparent color : 00,FF,00
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-03, 16:34:23
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global clockTiles		@ 128 unsigned chars
clockTiles:
	.word 0x22200000,0x11122000,0x11111200,0x11111120,0x11111120,0x11211112,0x12111112,0x21111112
	.word 0x00000022,0x00002211,0x00021111,0x00211111,0x00211211,0x02111121,0x02111112,0x02111111
	.word 0x11111112,0x11111112,0x11111120,0x11111120,0x11111200,0x11122000,0x22200000,0x00000000
	.word 0x02111111,0x02111111,0x00211111,0x00211111,0x00021111,0x00002211,0x00000022,0x00000000

	.section .rodata
	.align	2
	.global clockPal		@ 32 unsigned chars
clockPal:
	.hword 0x03E0,0x77BD,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(clock)
