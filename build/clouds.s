
@{{BLOCK(clouds)

@=======================================================================
@
@	clouds, 256x256@4, 
@	+ palette 16 entries, not compressed
@	+ 62 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 32x32 
@	Total size: 32 + 1984 + 2048 = 4064
@
<<<<<<< HEAD
@	Time-stamp: 2019-01-07, 18:22:52
=======
@	Time-stamp: 2019-01-07, 18:48:34
>>>>>>> master
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global cloudsTiles		@ 1984 unsigned chars
cloudsTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x60000000,0x56000000,0x55600000,0x55540000
	.word 0x26400000,0x55524000,0x55555610,0x55555554,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x07625552,0x25555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x00000000,0x00000016,0x00000425,0x00002555,0x00125555,0x01255555,0x02555555,0x25555555
	.word 0x55551000,0x55552000,0x55555700,0x55555500,0x55555560,0x55555550,0x55555556,0x55555555
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x00000006,0x00000015,0x00000025,0x00000455,0x00000555,0x00006555,0x00005555,0x00045555

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x60000000,0x57000000,0x55000000,0x55200000
	.word 0x00000000,0x00000000,0x04666400,0x55555554,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x00000000,0x00000000,0x00000000,0x00000007,0x00000065,0x00000455,0x00000555,0x00006555
	.word 0x40000000,0x20000000,0x50000000,0x54000000,0x52000000,0x55000000,0x55100000,0x55700000
	.word 0x00025555,0x00055555,0x00655555,0x00255555,0x00555555,0x04555555,0x02555555,0x05555555
	.word 0x55510000,0x55560000,0x55550000,0x55551000,0x55556000,0x55552000,0x55552000,0x55555000
	.word 0x00005555,0x00065555,0x00025555,0x00055555,0x00455555,0x00655555,0x00255555,0x00255555
	.word 0x55200000,0x55500000,0x55500000,0x55500000,0x55510000,0x55560000,0x55521000,0x55555210

	.word 0x05555555,0x15555555,0x45555555,0x65555555,0x25555555,0x25555555,0x55555555,0x55555555
	.word 0x00000000,0x60000000,0x56000000,0x55200000,0x55540000,0x55520000,0x55554000,0x55552000
	.word 0x55555641,0x55555522,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x04555555,0x22555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x00000000,0x00000007,0x00000025,0x00000255,0x00002555,0x00015555,0x00025555,0x00055555
	.word 0x00000000,0x20000000,0x52000000,0x55200000,0x55560000,0x55550000,0x55552000,0x55555100
	.word 0x55555556,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x00000004,0x00000465,0x00016555,0x00455555,0x07555555,0x45555555,0x55555555,0x55555555

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000001,0x00000002
	.word 0x55555000,0x55555100,0x55555400,0x55555600,0x55555600,0x55555200,0x55555600,0x55555600
	.word 0x00455555,0x00255555,0x00255555,0x00555555,0x00555555,0x00555555,0x00555555,0x00555555
	.word 0x55555200,0x55555510,0x55555560,0x55555550,0x55555551,0x55555556,0x55555555,0x55555555
	.word 0x00000065,0x00000055,0x00000655,0x00000555,0x00007555,0x00002555,0x00005555,0x00075555
	.word 0x55555400,0x55555100,0x55555000,0x55552000,0x55554000,0x55550000,0x55540000,0x55600000
	.word 0x00555555,0x00255555,0x00655555,0x00155555,0x00055555,0x00065555,0x00002555,0x00004555
	.word 0x10000000,0x60000000,0x60000000,0x20000000,0x50000000,0x50000000,0x50000000,0x50000000

	.word 0x00025555,0x00055555,0x00055555,0x00455555,0x00655555,0x00255555,0x00255555,0x00555555
	.word 0x56000000,0x40000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x56555555,0x40165552,0x00001110,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x55555555,0x55555555,0x25555524,0x06252610,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x55555555,0x55552145,0x46640004,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000755,0x00000042,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x50000000,0x50000000,0x50000000,0x50000000,0x20000000,0x20000000,0x60000000,0x40000000
	.word 0x00555555,0x00555555,0x00555555,0x00555555,0x00555555,0x00555555,0x00555555,0x00255555

	.word 0x55555555,0x55555555,0x55555552,0x55555554,0x55555550,0x55555520,0x55555540,0x55555500
	.word 0x00655555,0x00655555,0x00455555,0x00055555,0x00055555,0x00065555,0x00015555,0x00005555
	.word 0x55555600,0x55555000,0x55556000,0x55520000,0x55500000,0x55400000,0x54000000,0x40000000
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x25555555
	.word 0x00006555,0x00001555,0x00000255,0x00000155,0x00000025,0x00000015,0x00000007,0x00000000
	.word 0x55555521,0x55556100,0x64410000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x10655555,0x00016255,0x00000044,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x55555555,0x55555551,0x55555240,0x55552100,0x55210000,0x40000000,0x00000000,0x00000000

	.word 0x55555555,0x55555555,0x55555555,0x25555555,0x04255555,0x00004474,0x00000000,0x00000000
	.word 0x55564555,0x55600455,0x24000042,0x10000001,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x55555555,0x55555555,0x55555555,0x55555552,0x25522700,0x00000000,0x00000000,0x00000000
	.word 0x02555555,0x00255555,0x00065555,0x00004255,0x00000016,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10000000,0x51000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00004226,0x00065555
	.word 0x55000000,0x55600000,0x55500000,0x55500000,0x55540000,0x55560000,0x55554000,0x55555600
	.word 0x00455555,0x00255555,0x01555555,0x06555555,0x02555555,0x05555555,0x45555555,0x55555555

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000012
	.word 0x55555520,0x55555551,0x55555552,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x00000055,0x00000255,0x00000555,0x00007555,0x00006555,0x00002555,0x00002555,0x00002555
	.word 0x55555555,0x55555552,0x55555551,0x55555520,0x55555200,0x21464000,0x00000000,0x00000000
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x66445555,0x00001666,0x00000000
	.word 0x00006555,0x00001555,0x00000555,0x00000355,0x00000025,0x00000004,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global cloudsMap		@ 2048 unsigned chars
cloudsMap:
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

	.hword 0x0000,0x0000,0x0000,0x0000,0x0001,0x0002,0x0003,0x0004
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0005,0x0006,0x0006,0x0006
	.hword 0x0007,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0008,0x0009
	.hword 0x000A,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x000B,0x0006,0x0006,0x0006,0x0006
	.hword 0x000C,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x000D,0x0006
	.hword 0x000E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x000F,0x0006,0x0006,0x0006,0x0006
	.hword 0x0010,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0011,0x0012,0x0006
	.hword 0x0013,0x0014,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0015,0x0016,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x0017,0x0018,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0019,0x0006,0x0006
	.hword 0x0006,0x001A,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x001B,0x0006,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x0006,0x001C,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x001D,0x0006,0x0006
	.hword 0x0006,0x001E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x001F,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x0006,0x0020,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0021,0x0022,0x0023
	.hword 0x0024,0x0025,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0026,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x0006,0x0027,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0028,0x0006,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x0006,0x0029,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x002A,0x0006,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x002B,0x002C,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x002D,0x002E,0x002F,0x0030,0x0031
	.hword 0x0032,0x0033,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
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
	.hword 0x0034,0x0035,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0036,0x0037,0x0038,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0039,0x0006,0x003A,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x003B,0x003C,0x003D,0x0000,0x0000,0x0000,0x0000,0x0000
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
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.section .rodata
	.align	2
	.global cloudsPal		@ 32 unsigned chars
cloudsPal:
	.hword 0x7F95,0x7FDB,0x7FFE,0x7FDD,0x7FDC,0x7FFF,0x7FFD,0x7FFC
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(clouds)
