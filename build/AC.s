
@{{BLOCK(AC)

@=======================================================================
@
@	AC, 16x16@4, 
@	Transparent color : 00,FF,00
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2018-12-06, 11:15:34
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ACTiles		@ 128 unsigned chars
ACTiles:
	.word 0x44444442,0x43434342,0x43434342,0x43434342,0x43434342,0x44444442,0x43434342,0x43434342
	.word 0x00000004,0x00000014,0x00000014,0x00000014,0x00000014,0x00000014,0x00000014,0x00000014
	.word 0x43434342,0x43434342,0x44444442,0x44444442,0x22222222,0x00220000,0x00002200,0x00000022
	.word 0x00000014,0x00000014,0x00000004,0x00000004,0x00000002,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global ACPal		@ 32 unsigned chars
ACPal:
	.hword 0x03EE,0x5EF7,0x1084,0x318C,0x739D,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(AC)
