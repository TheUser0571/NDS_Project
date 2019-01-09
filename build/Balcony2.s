
@{{BLOCK(Balcony2)

@=======================================================================
@
@	Balcony2, 24x16@4, 
@	Transparent color : 00,FF,00
@	+ palette 16 entries, not compressed
@	+ 6 tiles not compressed
@	Total size: 32 + 192 = 224
@
@	Time-stamp: 2019-01-09, 14:58:39
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global Balcony2Tiles		@ 192 unsigned chars
Balcony2Tiles:
	.word 0x00050000,0x00575000,0x00054000,0x00440000,0x00040000,0x01111100,0x22222222,0x22222222
	.word 0x00030000,0x00333000,0x03333300,0x03333300,0x00333000,0x01111100,0x22222222,0x22222222
	.word 0x00000000,0x06060600,0x04040400,0x00444000,0x00444000,0x01111100,0x22222222,0x22222222
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222

	.section .rodata
	.align	2
	.global Balcony2Pal		@ 32 unsigned chars
Balcony2Pal:
	.hword 0x03E0,0x254F,0x4E73,0x1E27,0x2AA9,0x7FFF,0x001A,0x1FBF
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(Balcony2)
