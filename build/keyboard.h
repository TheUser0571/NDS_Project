
//{{BLOCK(keyboard)

//======================================================================
//
//	keyboard, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 430 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 27520 + 1536 = 29568
//
//	Time-stamp: 2019-01-08, 17:51:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_KEYBOARD_H
#define GRIT_KEYBOARD_H

#define keyboardTilesLen 27520
extern const unsigned int keyboardTiles[6880];

#define keyboardMapLen 1536
extern const unsigned short keyboardMap[768];

#define keyboardPalLen 512
extern const unsigned short keyboardPal[256];

#endif // GRIT_KEYBOARD_H

//}}BLOCK(keyboard)
