
//{{BLOCK(start)

//======================================================================
//
//	start, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 194 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 12416 + 1536 = 14464
//
//	Time-stamp: 2019-01-08, 11:12:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_START_H
#define GRIT_START_H

#define startTilesLen 12416
extern const unsigned int startTiles[3104];

#define startMapLen 1536
extern const unsigned short startMap[768];

#define startPalLen 512
extern const unsigned short startPal[256];

#endif // GRIT_START_H

//}}BLOCK(start)
