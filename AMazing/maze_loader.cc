#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "maze_loader.h"
#include "lodepng.h"

using std::vector;

Maze::Maze(dirmap dm, mazepoint mp, dir d) : cells(dm), exitcell(mp), exitdir(d) { }

Maze::~Maze() { }

unsigned char get_pixel(std::vector<unsigned char>& img,
        unsigned int x, unsigned int y, unsigned int channel,
		unsigned int w) {
	return img[y * w * 4 + x * 4 + channel];
}

bool black(std::vector<unsigned char> img, uint x, uint y, uint w) {
	return get_pixel(img, x, y, 0, w) == 0 &&
	       get_pixel(img, x, y, 1, w) == 0 &&
	       get_pixel(img, x, y, 2, w) == 0;
}

bool white(std::vector<unsigned char> img, uint x, uint y, uint w) {
	return get_pixel(img, x, y, 0, w) == 255 &&
	       get_pixel(img, x, y, 1, w) == 255 &&
	       get_pixel(img, x, y, 2, w) == 255;
}

bool green(std::vector<unsigned char> img, uint x, uint y, uint w) {
	return get_pixel(img, x, y, 0, w) == 0 &&
	       get_pixel(img, x, y, 1, w) == 255 &&
	       get_pixel(img, x, y, 2, w) == 0;
}

bool blue(std::vector<unsigned char> img, uint x, uint y, uint w) {
	return get_pixel(img, x, y, 0, w) == 0 &&
	       get_pixel(img, x, y, 1, w) == 0 &&
	       get_pixel(img, x, y, 2, w) == 255;
}

bool red(std::vector<unsigned char> img, uint x, uint y, uint w) {
	return get_pixel(img, x, y, 0, w) == 255 &&
	       get_pixel(img, x, y, 1, w) == 0 &&
	       get_pixel(img, x, y, 2, w) == 0;
}

Maze load_png(std::string filename) {
	vector<unsigned char> img;
	unsigned int w, h;
	unsigned int error = lodepng::decode(img, w, h, filename);
	
	if (error) {
		throw "Can't read maze";
	}

	dirmap cells;
	for (uint x = 1; x < w - 1; x += 2) {
		for (uint y = 1; y < h - 1; y += 2) {
			if (white(img, x, y, w)) {
				mazepoint p = std::make_pair(x/2, y/2);
				bool dirs[4];
				dirs[EAST]  = !black(img, x+1, y, w);
				dirs[NORTH] = !black(img, x, y-1, w);
				dirs[WEST]  = !black(img, x-1, y, w);
				dirs[SOUTH] = !black(img, x, y+1, w);
				auto pair = std::make_pair(p, dirs);
				cells.insert(pair);
			}
		}
	}

	mazepoint exitcell;
	dir exitdir = 0;
	return Maze(cells, exitcell, exitdir);
}

int main() {
	load_png("testimport.png");
}
