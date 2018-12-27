
@{{BLOCK(rainbow2)

@=======================================================================
@
@	rainbow2, 32x64@4, 
@	Transparent color : 00,FF,00
@	+ palette 16 entries, not compressed
@	+ 32 tiles not compressed
@	Total size: 32 + 1024 = 1056
@
@	Time-stamp: 2018-12-27, 14:54:18
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global rainbow2Tiles		@ 1024 unsigned chars
rainbow2Tiles:
	.word 0x22200000,0x22000000,0x20000000,0x00000000,0x00000000,0x00000000,0x20000000,0x22000000
	.word 0x55544442,0x55444422,0x54444222,0x44442222,0x44442222,0x44442222,0x54444222,0x55444422
	.word 0x11133335,0x11333355,0x13333555,0x33335555,0x33335555,0x33335555,0x13333555,0x11333355
	.word 0x00000001,0x00000011,0x00000111,0x00001111,0x00001111,0x00001111,0x00000111,0x00000011
	.word 0x22200000,0x22200000,0x22200000,0x22000000,0x20000000,0x00000000,0x00000000,0x00000000
	.word 0x55544442,0x55544442,0x55544442,0x55444422,0x54444222,0x44442222,0x44442222,0x44442222
	.word 0x11133335,0x11133335,0x11133335,0x11333355,0x13333555,0x33335555,0x33335555,0x33335555
	.word 0x00000001,0x00000001,0x00000001,0x00000011,0x00000111,0x00001111,0x00001111,0x00001111

	.word 0x20000000,0x22000000,0x22200000,0x22200000,0x22200000,0x22000000,0x20000000,0x00000000
	.word 0x54444222,0x55444422,0x55544442,0x55544442,0x55544442,0x55444422,0x54444222,0x44442222
	.word 0x13333555,0x11333355,0x11133335,0x11133335,0x11133335,0x11333355,0x13333555,0x33335555
	.word 0x00000111,0x00000011,0x00000001,0x00000001,0x00000001,0x00000011,0x00000111,0x00001111
	.word 0x00000000,0x00000000,0x20000000,0x22000000,0x22200000,0x22200000,0x22200000,0x22000000
	.word 0x44442222,0x44442222,0x54444222,0x55444422,0x55544442,0x55544442,0x55544442,0x55444422
	.word 0x33335555,0x33335555,0x13333555,0x11333355,0x11133335,0x11133335,0x11133335,0x11333355
	.word 0x00001111,0x00001111,0x00000111,0x00000011,0x00000001,0x00000001,0x00000001,0x00000011

	.word 0x20000000,0x00000000,0x00000000,0x00000000,0x20000000,0x22000000,0x22200000,0x22200000
	.word 0x54444222,0x44442222,0x44442222,0x44442222,0x54444222,0x55444422,0x55544442,0x55544442
	.word 0x13333555,0x33335555,0x33335555,0x33335555,0x13333555,0x11333355,0x11133335,0x11133335
	.word 0x00000111,0x00001111,0x00001111,0x00001111,0x00000111,0x00000011,0x00000001,0x00000001
	.word 0x22200000,0x22000000,0x20000000,0x00000000,0x00000000,0x00000000,0x20000000,0x22000000
	.word 0x55544442,0x55444422,0x54444222,0x44442222,0x44442222,0x44442222,0x54444222,0x55444422
	.word 0x11133335,0x11333355,0x13333555,0x33335555,0x33335555,0x33335555,0x13333555,0x11333355
	.word 0x00000001,0x00000011,0x00000111,0x00001111,0x00001111,0x00001111,0x00000111,0x00000011

	.word 0x22200000,0x22200000,0x22200000,0x22000000,0x20000000,0x00000000,0x00000000,0x00000000
	.word 0x55544442,0x55544442,0x55544442,0x55444422,0x54444222,0x44442222,0x44442222,0x44442222
	.word 0x11133335,0x11133335,0x11133335,0x11333355,0x13333555,0x33335555,0x33335555,0x33335555
	.word 0x00000001,0x00000001,0x00000001,0x00000011,0x00000111,0x00001111,0x00001111,0x00001111
	.word 0x20000000,0x22000000,0x22200000,0x22200000,0x22200000,0x22000000,0x20000000,0x00000000
	.word 0x54444222,0x55444422,0x55544442,0x55544442,0x55544442,0x55444422,0x54444222,0x44442222
	.word 0x13333555,0x11333355,0x11133335,0x11133335,0x11133335,0x11333355,0x13333555,0x33335555
	.word 0x00000111,0x00000011,0x00000001,0x00000001,0x00000001,0x00000011,0x00000111,0x00001111

	.section .rodata
	.align	2
	.global rainbow2Pal		@ 32 unsigned chars
rainbow2Pal:
	.hword 0x03E0,0x001A,0x7D26,0x027F,0x0B6C,0x1FBF,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(rainbow2)
