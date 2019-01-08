
@{{BLOCK(rainbow)

@=======================================================================
@
@	rainbow, 16x16@4, 
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
	.global rainbowTiles		@ 128 unsigned chars
rainbowTiles:
	.word 0x11100000,0x44411000,0x44444100,0x33333310,0x33333310,0x77777771,0x77777771,0x66666661
	.word 0x00000011,0x00001144,0x00014444,0x00133333,0x00133333,0x01777777,0x01777777,0x01666666
	.word 0x66666661,0x22222221,0x22222210,0x55555510,0x55555100,0x88811000,0x11100000,0x00000000
	.word 0x01666666,0x01222222,0x00122222,0x00155555,0x00015555,0x00001188,0x00000011,0x00000000

	.section .rodata
	.align	2
	.global rainbowPal		@ 32 unsigned chars
rainbowPal:
	.hword 0x03E0,0x0000,0x7D26,0x027F,0x001A,0x7C15,0x0B6C,0x1FBF
	.hword 0x7C1A,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(rainbow)
