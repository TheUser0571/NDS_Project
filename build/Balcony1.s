
@{{BLOCK(Balcony1)

@=======================================================================
@
@	Balcony1, 16x16@4, 
@	Transparent color : 00,FF,00
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2018-12-28, 13:24:26
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global Balcony1Tiles		@ 128 unsigned chars
Balcony1Tiles:
	.word 0x00030000,0x00353000,0x00031000,0x00110000,0x00010000,0x04444400,0x22222222,0x22222222
	.word 0x00010000,0x00111000,0x01111100,0x01111100,0x00111000,0x04444400,0x22222222,0x22222222
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222

	.section .rodata
	.align	2
	.global Balcony1Pal		@ 32 unsigned chars
Balcony1Pal:
	.hword 0x03E0,0x2AA9,0x4E73,0x7FFF,0x254F,0x1FBF,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(Balcony1)
