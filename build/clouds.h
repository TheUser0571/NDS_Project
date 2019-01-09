
//{{BLOCK(clouds)

//======================================================================
//
//	clouds, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 62 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 1984 + 2048 = 4064
//
//	Time-stamp: 2019-01-08, 17:51:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CLOUDS_H
#define GRIT_CLOUDS_H

#define cloudsTilesLen 1984
extern const unsigned int cloudsTiles[496];

#define cloudsMapLen 2048
extern const unsigned short cloudsMap[1024];

#define cloudsPalLen 32
extern const unsigned short cloudsPal[16];

#endif // GRIT_CLOUDS_H

//}}BLOCK(clouds)
