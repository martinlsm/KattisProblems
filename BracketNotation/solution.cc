#include <vector>
#include <stack>
#include <assert.h>
#include <algorithm>
#include <cmath>
#include <iostream>

#define DEBUG

using namespace std;

long num_len(long n) {
	if (n == 0)
		return 1;
	long len = 0;
	while (n > 0) {
		++len;
		n /= 10;
	}
	return len;
}

struct Vertex {
	long s;
	long e;
	long len;
	vector<Vertex*> children;

	Vertex();
	~Vertex();
	void add_child(Vertex*);
	bool update(long start_index);
	bool update_tree();
	void print();
	long get_str_len();
};

Vertex::Vertex() {
	s = 0;
	e = 0;
	len = 4;
}

Vertex::~Vertex() {
	for (Vertex* c : children)
		delete c;
}

void Vertex::add_child(Vertex* c) {
	children.push_back(c);
}

bool Vertex::update(long start_index) {
	long new_s;
	bool changed;

	new_s = start_index + len;

	changed = new_s != s;

	len = 2 + num_len(new_s) + num_len(e);
	s = new_s;

	long child_start = s;
	for (Vertex* c : children) {
		changed |= c->update(child_start);
		child_start = c->get_str_len();
	}

	if (children.size() == 0)
		e = s;
	else
		e = children[children.size() - 1]->e;
	len = 2 + num_len(new_s) + num_len(e);

	return changed;
}

long Vertex::get_str_len() {
	if (children.empty())
		return e;
	else
		return children[children.size() - 1]->get_str_len();
}

void Vertex::print() {
	cout << s << "," << e << ":";
	for (Vertex* c : children)
		c->print();
}

void debug_print(Vertex* v) {
	cout << "\t" << v->s << "\t" << v->e << "\t" << v->len << "\n";
	for (Vertex* c : v->children)
		debug_print(c);
}

bool Vertex::update_tree() {
	return false;
}

vector<Vertex*> parse_trees(string s) {
	vector<Vertex*> trees;
	stack<Vertex*> vstack;
	string::iterator c = s.begin();
	while (c != s.end()) {
		if (*c == '(') {
			Vertex* v = new Vertex;
			if (!vstack.empty())
				vstack.top()->add_child(v);
			vstack.push(v);
		} else {
			if (vstack.size() == 1) {
				trees.push_back(vstack.top());
			}
			vstack.pop();
		}
		++c;
	}
	return trees;
}

void print_bracket_format(string s) {
	vector<Vertex*> trees = parse_trees(s);
	long start_index = 0;
	for (Vertex* v : trees) {
		bool changed = true;
		while (changed) {
			changed = v->update(start_index);
		}
		start_index = v->get_str_len();
		v->print();
		delete v;
	}
	cout << endl;
}

int main() {
	string input;
	cin >> input;
	print_bracket_format(input);
}
