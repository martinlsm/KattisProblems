#ifndef MAZE_LOADER_H
#define MAZE_LOADER_H

#include <map>
#include <vector>
#include <string>

using mazepoint = std::pair<int, int>;
using dirmap = std::map<mazepoint, std::vector<char>>;
using dir = char;


const dir EAST = 0;
const dir NORTH = 1;
const dir WEST = 2;
const dir SOUTH = 3;


struct Maze { 
	Maze(dirmap, mazepoint start);
	~Maze();
	dirmap cells; 
	dirmap::iterator playerpos;
	std::string moveplayer(dir);
};

Maze load_png(std::string filename);

#endif
