#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct TileSet
{
	uint firstgid				= 1;
	p2SString name 				= "Desert";
	uint tilewidth				= 32;
	uint tileheight				= 32;
	uint spacing				= 1;
	uint margin					= 1;
};

// TODO 1: Create a struct needed to hold the information to Map node
struct Map
{
	enum map_orientation
	{
		orthogonal,
		isometric,
		staggered,
		hexagonal,
	 };

	enum render_order
	{
		right_down,
		right_up,
		left_down,
		left_up,
	};

	map_orientation orientation = orthogonal;
	render_order order			= right_down;
	uint width					= 50;
	uint height					= 15;
	uint tilewidth				= 32;
	uint tileheight				= 32;
	uint nextobjectid			= 1;
	
};



// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

	bool FillMap(const Map*);

private:


public:

	Map Map;
	TileSet* tileset = new TileSet;

		// TODO 1: Add your struct for map info as public for now

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__