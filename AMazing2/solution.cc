#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>

using std::map;
using std::vector;
using std::pair;
using std::string;
using mazepos = pair<short, short>;
using dirmap = map<mazepos, vector<char>>;

const size_t RIGHT = 0;
const size_t UP    = 1;
const size_t LEFT  = 2;
const size_t DOWN  = 3;

string dir_str(size_t dir) {
	switch (dir) {
		case RIGHT:
			return "right";
		case UP:
			return "up";
		case LEFT:
			return "left";
		case DOWN:
			return "down";
	}
	throw string{"invalid dir index"};
}

void turn_left(size_t& dir) {
	dir = (dir + 1) % 4;
}

void turn_right(size_t& dir) {
	dir = (dir - 1) % 4;
}

void go_back(size_t& dir) {
	dir = (dir + 2) % 4;
}

int main() {
	dirmap dirs;
	dirs.insert({{0, 0}, {0, 0, 0, 0}});
	dirmap::iterator currpos = dirs.begin();
	size_t currdir = UP;
	while (true) {
		std::vector<size_t> dirsleft;
		for (size_t i = 0; i < 4; i++) {
			if (currpos->second[i] < 2) {
				dirsleft.push_back(i);
			}
		}
		if (dirsleft.size() == 0) {
			std::cout << "no way out" << std::endl;
			break;			
		} else if (std::find(dirsleft.begin(), dirsleft.end(), currdir) == dirsleft.end()) {
			currdir = dirsleft[rand() % dirsleft.size()];
		}
		std::cout << dir_str(currdir) << std::endl;
		string judge_response;
		std::cin >> judge_response;
		if (judge_response == "wall") {
			currpos->second[currdir] = 2;
			continue;
		} else if (judge_response == "ok") {
			++currpos->second[currdir];
			mazepos newpos = currpos->first;	
			switch (currdir) {
				case RIGHT:
					++newpos.first;	
					break;
				case UP:
					++newpos.second;
					break;
				case LEFT:
					--newpos.first;
					break;
				case DOWN:
					--newpos.second;
					break;
			}
			currpos = dirs.insert({newpos, {0,0,0,0}}).first;
		} else if (judge_response == "solved") {
			break;
		} else if (judge_response == "wrong") {
			return 1;
		} else {
			return 2;
		} 
	}
}
