
//{{BLOCK(backimage)

//======================================================================
//
//	backimage, 256x768@4, 
//	Transparent palette entry: 0.
//	+ palette 16 entries, not compressed
//	+ 1403 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x96 
//	Total size: 32 + 44896 + 6144 = 51072
//
//	Time-stamp: 2019-01-09, 11:05:57
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKIMAGE_H
#define GRIT_BACKIMAGE_H

#define backimageTilesLen 44896
extern const unsigned int backimageTiles[11224];

#define backimageMapLen 6144
extern const unsigned short backimageMap[3072];

#define backimagePalLen 32
extern const unsigned short backimagePal[16];

#endif // GRIT_BACKIMAGE_H

//}}BLOCK(backimage)
