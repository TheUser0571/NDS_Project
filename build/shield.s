
@{{BLOCK(shield)

@=======================================================================
@
@	shield, 16x16@4, 
@	Transparent color : 00,FF,00
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-07, 18:22:54
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global shieldTiles		@ 128 unsigned chars
shieldTiles:
	.word 0x11000000,0x32100000,0x32211000,0x32222110,0x32222210,0x32222210,0x32222210,0x32222210
	.word 0x00000000,0x00000001,0x00000113,0x00011333,0x00013333,0x00013333,0x00013333,0x00013333
	.word 0x32222100,0x32222100,0x32222100,0x32221000,0x32221000,0x32210000,0x32100000,0x11000000
	.word 0x00001333,0x00001333,0x00001333,0x00000133,0x00000133,0x00000013,0x00000001,0x00000000

	.section .rodata
	.align	2
	.global shieldPal		@ 32 unsigned chars
shieldPal:
	.hword 0x03E0,0x0000,0x39CE,0x5EF7,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(shield)
