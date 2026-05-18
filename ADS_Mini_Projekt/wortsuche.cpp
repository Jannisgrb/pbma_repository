#include <iostream>
#include <vector>
#include "pbma.h"
#include "common.h"
using namespace std;

int main(int argc, const char* argv[]){
	args_t args(argc, argv);
	string fname = args.pos(0, "grid1.txt");

	vector<string> grid = read_words(fname);
	if (grid.size() == 0){
		throw runtime_error("Fehler: Grid konnte nicht gelesen werden.");
	}

	if ((int)grid.size() != stoi(grid[0]) + 1){
		throw runtime_error("Fehler: Grid ist nicht quadratisch!");
	}

	for(size_t i = 1; i < grid.size(); ++i){
		if ((int)grid[i].size() != stoi(grid[0])){
			throw runtime_error("Fehler: Grid ist nicht quadratisch!");
		}
	}

	for(size_t i = 1; i < grid.size(); ++i){
		for (size_t j = 0; j < grid[i].size(); ++j){
			grid[i][j] = tolower(grid[i][j]);
		}
	}

	string wort;

	while (cin >> wort){
		for(size_t i = 0; i < wort.length(); ++i){
			wort[i] = tolower(wort[i]);
		}

		Suchaufruf(wort, grid);
	}

	

	return 0;

}
