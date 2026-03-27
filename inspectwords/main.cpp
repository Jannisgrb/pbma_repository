#include <iostream>
#include <vector>
#include <ostream>
#include "pbma.h"
using namespace std;

int word_counter(vector<string> words);
int letters_counter(vector<string> words);
int longest_word(vector<string> words);
int shortest_word(vector<string> words);

int main(int argc, const char* argv[]){
	args_t args(argc, argv);
	string fname = args.pos(0, "woerter.dat");

	vector<string> woerter = read_words(fname);

	cout << "Anzahl der Wörter: " << word_counter(woerter) << endl;
	cout << "Anzahl der Buchstaben: " << letters_counter(woerter) << endl;
	cout << "Länge des längsten Wortes: " << longest_word(woerter) << endl;
	cout << "Länge des kürzesten Wortes: " << shortest_word(woerter) << endl;

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


int longest_word(vector<string> words){
	unsigned int longest = words[1].size();
	for(unsigned int i = 0; i < words.size(); i++){
		if (words[i].size() > longest){
			longest = words[i].size();
		}
	}
	return longest;
}


int shortest_word(vector<string> words){
	unsigned int shortest = words[1].size();
	for(unsigned int i = 0; i < words.size(); i++){
		if (words[i].size() < shortest){
			shortest = words[i].size();
		}
	}
	return shortest;
}