#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

int main(int argc, const char* argv[]){
	args_t args(argc, argv);
	string fname = args.pos(0, "numbers.txt");

	vector<int> numbers = read_ints(fname);

	int Maximum = numbers[0];

	for(size_t i = 0; i < numbers.size(); ++i){
		if (numbers[i] > Maximum){
			Maximum = numbers[i];
		}
	}

	cout << "Es gibt " << numbers.size() << " Zahlen und das Maximum ist " << Maximum << endl;
}
