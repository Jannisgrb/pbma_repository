#ifndef COMMON_H_
#define COMMON_H_
using namespace std;

typedef struct {
	int Zeile;
	int Spalte;
} Ort;

typedef struct {
	string word;
	int Zeile;
	int Spalte;
	char Richtung;
	bool enthalten;
} Result;

void Suchaufruf(string word, vector<string> grid);

Result Wortsuche_Rechts(string word, vector<string> grid, Ort start);
Result Wortsuche_Links(string word, vector<string> grid, Ort start);
Result Wortsuche_Unten(string word, vector<string> grid, Ort start);
Result Wortsuche_Oben(string word, vector<string> grid, Ort start);
vector<string> mach_woerter_aus_zeile(string in);

#endif
