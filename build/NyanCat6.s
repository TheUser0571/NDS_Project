
@{{BLOCK(NyanCat6)

@=======================================================================
@
@	NyanCat6, 32x32@8, 
@	Transparent color : 00,FF,00
@	+ palette 256 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 512 + 1024 = 1536
@
@	Time-stamp: 2019-01-08, 17:51:42
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global NyanCat6Tiles		@ 1024 unsigned chars
NyanCat6Tiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x02000000,0x00000000,0x04020000,0x00000000,0x04040200,0x00000000,0x07040200
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x02020202,0x02020202,0x04040404,0x04040404,0x07070707,0x07070707,0x07070707,0x07070507
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x02020202,0x02020202,0x04040404,0x04040404,0x07070707,0x04070707,0x07070707,0x07070705
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000002,0x00000000,0x00000208,0x00000000,0x00000204,0x00000000

	.word 0x00000000,0x07040200,0x00000000,0x07040200,0x00000000,0x07040200,0x00000000,0x07040200
	.word 0x00000000,0x07040200,0x00000000,0x07040200,0x00000000,0x07040202,0x02020000,0x07040201
	.word 0x07070507,0x07070707,0x07070707,0x07070707,0x07070707,0x07050707,0x07070707,0x07070707
	.word 0x07070507,0x07070707,0x07070707,0x07070707,0x07070707,0x07070707,0x07070707,0x07070705
	.word 0x07070707,0x07070707,0x02020707,0x07070707,0x01010207,0x07050702,0x01010207,0x07070201
	.word 0x01010207,0x02020101,0x01010207,0x01010101,0x01010102,0x01010101,0x01010102,0x01010206
	.word 0x00000204,0x00000000,0x00000204,0x00000202,0x02000204,0x00020101,0x01020204,0x00020101
	.word 0x01010202,0x00020101,0x01010101,0x00020101,0x01010101,0x02010101,0x06010101,0x02010102

	.word 0x01010200,0x07040201,0x02010102,0x07040202,0x02010102,0x07040200,0x00020200,0x04040200
	.word 0x00000000,0x04020200,0x00000000,0x02010102,0x00000000,0x02010102,0x00000000,0x00020202
	.word 0x07070705,0x07070707,0x07070707,0x07070707,0x07050707,0x07050707,0x07070707,0x07070707
	.word 0x04040404,0x04040404,0x02020202,0x02020202,0x01010200,0x00000002,0x02020000,0x00000002
	.word 0x01010102,0x01010202,0x03030102,0x01010101,0x03030102,0x01010201,0x01010207,0x02020201
	.word 0x01020404,0x01010101,0x02020202,0x02020202,0x02000000,0x00020101,0x00000000,0x00020202
	.word 0x02010201,0x02010102,0x01010101,0x02030301,0x02010102,0x02030301,0x02020202,0x00020101
	.word 0x01010101,0x00000201,0x02020202,0x00000002,0x02010102,0x00000000,0x02020200,0x00000000

	.section .rodata
	.align	2
	.global NyanCat6Pal		@ 512 unsigned chars
NyanCat6Pal:
	.hword 0x03E0,0x4E73,0x0000,0x4E7D,0x53BF,0x2855,0x7FFF,0x5A3E
	.hword 0x63DF,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(NyanCat6)
