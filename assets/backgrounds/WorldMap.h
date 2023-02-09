
//{{BLOCK(WorldMap)

//======================================================================
//
//	WorldMap, 256x256@4, 
//	+ palette 4 entries, not compressed
//	+ 9 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 8 + 288 + 2048 = 2344
//
//	Time-stamp: 2023-02-06, 09:27:43
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WORLDMAP_H
#define GRIT_WORLDMAP_H

#define WorldMapTilesLen 288
extern const unsigned int WorldMapTiles[72];

#define WorldMapMapLen 2048
extern const unsigned int WorldMapMap[512];

#define WorldMapPalLen 8
extern const unsigned int WorldMapPal[2];

#endif // GRIT_WORLDMAP_H

//}}BLOCK(WorldMap)
