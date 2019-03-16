#ifndef MAZE_LOADER_H
#define MAZE_LOADER_H

#include <map>
#include <vector>

using mazepoint = std::pair<uint, uint>;
using dirmap = std::map<mazepoint, bool[4]>;
using dir = char;

const dir EAST = 0;
const dir NORTH = 1;
const dir WEST = 2;
const dir SOUTH = 3;

struct Maze { 
	Maze(dirmap, mazepoint exitcell, dir exitdir);
	~Maze();
	dirmap cells; 
	const mazepoint exitcell;
	const dir exitdir;
};

Maze load_png(std::string filename);

#endif
