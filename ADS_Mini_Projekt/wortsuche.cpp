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

	if (grid.size() != stoi(grid[0]) + 1){
		throw runtime_error("Fehler: Grid ist nicht quadratisch!");
	}

	for(size_t i = 1; i < grid.size(); ++i){
		if (grid[i].size() != stoi(grid[0])){
			throw runtime_error("Fehler: Grid ist nicht quadratisch!");
		}
	}

	for(size_t i = 1; i < grid.size(); ++i){
		for (size_t j = 0; j < grid[i].size(); ++j){
			grid[i][j] = tolower(grid[i][j]);
		}
	}

	vector<string> suchwoerter;

	string wort;

	cin >> wort;
		
	suchwoerter.push_back(wort);


	for(size_t i = 0; i < suchwoerter.size(); ++i){
		for(size_t j = 0; j < suchwoerter[i].size(); ++j){
			suchwoerter[i][j] = tolower(suchwoerter[i][j]);
		}
		Suchaufruf(suchwoerter[i], grid);
	}

	return 0;

}
