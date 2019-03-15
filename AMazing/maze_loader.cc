#include "maze_loader.h"

Maze::Maze(dirmap dm, mazepoint mp, dir d) : cells(dm), exitcell(mp), exitdir(d) { }

Maze::~Maze() { }

// Maze load_png(std::string filename) {
// 	dirmap cells;
// 	mazepoint exitcell;
// 	dir exitdir = 0;
// 	return Maze(cells, exitcell, exitdir);
// }
