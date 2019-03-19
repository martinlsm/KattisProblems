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
using dirmap = map<mazepos, vector<bool>>;

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

int main() {
	dirmap dirs;
	dirs.insert({{0, 0}, {0, 0, 0, 0}});
	dirmap::iterator currpos = dirs.begin();
	while (true) {
		std::vector<size_t> dirsleft;
		for (size_t i = 0; i < 4; i++) {
			if (!currpos->second[i]) {
				dirsleft.push_back(i);
			}
		}
		if (dirsleft.size() == 0) {
			std::cout << "no way out" << std::endl;
			break;			
		}
		size_t rand_dir = rand() % dirsleft.size();	
		currpos->second[rand_dir] = true;
		std::cout << dir_str(rand_dir) << std::endl;
		string judge_response;
		std::cin >> judge_response;
		if (judge_response == "wall") {
			continue;
		} else if (judge_response == "ok") {
			mazepos newpos = currpos->first;	
			switch (rand_dir) {
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
			throw string{"error, got \"wrong\" from the judge"};
		} else {
			throw string{"received incorrect reponse from the judge"};
		} 
	}
}
