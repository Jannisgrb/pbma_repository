#include "iostream"
#include "pbma.h"
#include <vector>

using namespace std;

void Auszaehler(vector<string> &names, bool verbose);

int main(int argc, const char* argv[]){
	args_t args(argc, argv);
	
	vector<string> names;
	names.push_back(args.pos(0, "Rudi"));
	names.push_back(args.pos(1, "Susi"));
	names.push_back(args.pos(2, "Votan"));
	names.push_back(args.pos(3, "Bodo"));
	names.push_back(args.pos(4, "Jonny"));
	names.push_back(args.pos(5, "Hermine"));
	names.push_back(args.pos(6, "Angelika"));
	names.push_back(args.pos(7, "Elli"));
	names.push_back(args.pos(8, "Riki"));
	names.push_back(args.pos(9, "Emanuel"));
	names.push_back(args.pos(10, "Felix"));
	names.push_back(args.pos(11, "Gerhard"));

	bool verbose = args.flag("-v") || true;

	Auszaehler(names, verbose);
}


void Auszaehler(vector<string> &names, bool verbose){
	int aktuellerIndex = 0;
	const int schritte = 7;

	while(names.size() > 1){
		aktuellerIndex = (aktuellerIndex + schritte - 1) % names.size();

		if(verbose){
			cout << names[aktuellerIndex] << " fliegt raus!" << endl;
		}

		names.erase(names.begin() + aktuellerIndex);	
	}
	
	cout << "Gewinner: " << names[0] << endl;
}
