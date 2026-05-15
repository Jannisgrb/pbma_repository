#include <iostream>
#include <vector>
#include "pbma.h"
#include "common.h"
using namespace std;

int main(int argc, const char* argv[]){
	args_t args(argc, argv);
	string fname = args.pos(0, "grid1.txt");
	args.pos(1, "blau");
	args.pos(2, "rot");
	args.pos(3, "gold");
	args.pos(4, "pink");
	args.pos(5, "silber");

	vector<string> grid = read_words(fname);

	cout << grid[0] << endl;

}
