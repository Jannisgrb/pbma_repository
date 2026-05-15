#include <iostream>
#include <vector>
#include "pbma.h"
#include "common.h"
using namespace std;

void Anfangsbuchstaben_Suche(string word, vector<string> grid){
	char Anfangsbuchstabe = word[0];
	for (size_t i = 0; i < grid.size(); ++i){
		for(size_t j = 0; j < grid[i].size(); ++j){
			if(grid[i][j] == Anfangsbuchstabe){
//				Index start_index;
//				start_index.Zeile = i;
//				start_index.Spalte = j;
				Wortsuche(start_index, word, grid, "R");
			}
		}
	}
}

Result Wortsuche(Index start_index, string word, vector<string> grid, Direction Richtung){
//	for (size_t i = 1; i < word.size; i++){
//		for (size_t j = start_index.Spalte; j < grid[start_index.Zeile].size(); j++){
//			if(grid[start_index.Zeile][j] == word[i]){
//
//			}
//		}
//	}
}
