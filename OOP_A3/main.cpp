#include <iostream>
#include "header.h"
#include "pbma.h"
#include <vector>
using namespace std;

int main(int argc, const char* argv[]){
int x = 45;
int y = 10;
int ggt = ggt1(45, 10);
int ggt_2 = ggt2(45, 100);

	args_t args(argc, argv);
	string fname = args.pos(0, "ggts.dat"); // (position, default-Wert)
	Timer timer;
	vector<int> zahlen = read_ints(fname);
	cout << "lesen dauerte " << timer.human_measure() << endl;

cout << "Größter gemeinsamer Teiler von " << x << " & " << y << ": " << ggt << endl;
cout << "Größter gemeinsamer Teiler von " << x << " & " << y << ": " << ggt_2 << endl;

//Das ist die Version über VSCode mac

return 0;
}