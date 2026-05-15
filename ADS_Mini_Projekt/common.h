#ifndef COMMON_H_
#define COMMON_H_
using namespace std;

typedef struct{
	int Zeile;
	int Spalte;
	char Richtung;
}Direction;

typedef struct{
	string word;
	int Zeile;
	int Spalte;
	char Richtung;
	bool enthalten;
}Result;

//typedef struct{
//	int Zeile;
//	int Spalte;
//}Index;

void Anfangsbuchstaben_Suche(string word, vector<string> grid);

Result Wortsuche(Index start_index, string word, vector<string> grid, Direction Richtung);

#endif
