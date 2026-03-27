#include <iostream>
#include <vector>
#include <ostream>
#include "pbma.h"
using namespace std;

int word_counter(vector<string> words);
int letters_counter(vector<string> words);

int main(int argc, const char* argv[]){
	args_t args(argc, argv);
	string fname = args.pos(0, "woerter.dat");

	vector<string> woerter = read_words(fname);

	cout << "Anzahl der Wörter: " << word_counter(woerter) << endl;
	cout << "Anzahl der Buchstaben: " << letters_counter(woerter) << endl;


}

int word_counter(vector<string> words){
	return words.size();
}

int letters_counter(vector<string> words){
	int counter = 0;
	for(unsigned int i = 0; i < words.size(); i++){
		counter = counter + words[i].size();
	}
	return counter;
}
