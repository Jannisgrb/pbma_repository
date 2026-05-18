#include <iostream>
#include <vector>
#include "pbma.h"
#include "common.h"
using namespace std;

void Suchaufruf(string word, vector<string> grid) {
	char Anfangsbuchstabe = word[0];
	vector<Result> ergebnisse;
	Ort start;
	for (size_t i = 0; i < grid.size(); ++i) {
		for (size_t j = 0; j < grid[i].size(); ++j) {
			if (grid[i][j] == Anfangsbuchstabe) {
				start.Zeile = i;
				start.Spalte = j;

				Result ergebnis_rechts = Wortsuche_Rechts(word, grid, start);
				if (ergebnis_rechts.enthalten == 1) {
					ergebnisse.push_back(ergebnis_rechts);
				}

				Result ergebnis_links = Wortsuche_Links(word, grid, start);
				if (ergebnis_links.enthalten == 1) {
					ergebnisse.push_back(ergebnis_links);
				}

				Result ergebnis_unten = Wortsuche_Unten(word, grid, start);
				if (ergebnis_unten.enthalten == 1) {
					ergebnisse.push_back(ergebnis_unten);
				}

				Result ergebnis_oben = Wortsuche_Oben(word, grid, start);
				if (ergebnis_oben.enthalten == 1) {
					ergebnisse.push_back(ergebnis_oben);
				}

			}
		}
	}
	if (ergebnisse.size() == 0) {
		cout << word << " - Not Found" << endl;
	} else {
		for (size_t i = 0; i < ergebnisse.size(); ++i) {
			cout << ergebnisse[i].word << " " << ergebnisse[i].Zeile << " "
					<< ergebnisse[i].Spalte << " " << ergebnisse[i].Richtung
					<< endl;
		}
	}
}

Result Wortsuche_Rechts(string word, vector<string> grid, Ort start) {
	Result gefunden;
	gefunden.Spalte = start.Spalte;
	gefunden.Zeile = start.Zeile - 1;
	gefunden.word = word;
	gefunden.enthalten = 1;
	gefunden.Richtung = 'R';
	for (size_t i = 0; i < word.size(); i++) {
		if (start.Spalte + i >= stoi(grid[0])) {
			gefunden.enthalten = 0;
			break;
		}
		if (grid[start.Zeile][start.Spalte + i] != word[i]) {
			gefunden.enthalten = 0;
			break;
		}
	}
	return gefunden;
}

Result Wortsuche_Links(string word, vector<string> grid, Ort start) {
	Result gefunden;
	gefunden.Spalte = start.Spalte;
	gefunden.Zeile = start.Zeile - 1;
	gefunden.word = word;
	gefunden.enthalten = 1;
	gefunden.Richtung = 'L';
	for (size_t i = 0; i < word.size(); i++) {
		if (start.Spalte - i < 0) {
			gefunden.enthalten = 0;
			break;
		}
		if (grid[start.Zeile][start.Spalte - i] != word[i]) {
			gefunden.enthalten = 0;
			break;
		}
	}
	return gefunden;
}

Result Wortsuche_Unten(string word, vector<string> grid, Ort start) {
	Result gefunden;
	gefunden.Spalte = start.Spalte;
	gefunden.Zeile = start.Zeile - 1;
	gefunden.word = word;
	gefunden.enthalten = 1;
	gefunden.Richtung = 'D';
	for (size_t i = 0; i < word.size(); i++) {
		if (start.Zeile + i >= stoi(grid[0])) {
			gefunden.enthalten = 0;
			break;
		}
		if (grid[start.Zeile + i][start.Spalte] != word[i]) {
			gefunden.enthalten = 0;
			break;
		}
	}
	return gefunden;
}

Result Wortsuche_Oben(string word, vector<string> grid, Ort start) {
	Result gefunden;
	gefunden.Spalte = start.Spalte;
	gefunden.Zeile = start.Zeile - 1;
	gefunden.word = word;
	gefunden.enthalten = 1;
	gefunden.Richtung = 'U';
	for (size_t i = 0; i < word.size(); i++) {
		if (start.Zeile - i <= 0) {
			gefunden.enthalten = 0;
			break;
		}
		if (grid[start.Zeile - i][start.Spalte] != word[i]) {
			gefunden.enthalten = 0;
			break;
		}
	}
	return gefunden;
}

vector<string> mach_woerter_aus_zeile(string in) {
	vector<string> erg;
	size_t in_idx = 0;
	erg.push_back("");
	while (in_idx < in.length()) {
		if (in[in_idx] != ' ') {
			erg.back().push_back(in[in_idx]);
		} else {
			erg.push_back("");
		}
		in_idx++;
	}
	return erg;
}
