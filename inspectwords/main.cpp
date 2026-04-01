#include <iostream>
#include <vector>
#include <ostream>
#include "pbma.h"
using namespace std;

int word_counter(vector<string> words);
int letters_counter(vector<string> words);
int longest_word(vector<string> words);
int shortest_word(vector<string> words);
vector<int> start_letter_counter(vector<string> words);
void start_letters_out(vector<int> counter);

int main(int argc, const char* argv[]){
	args_t args(argc, argv);
	string fname = args.pos(0, "woerter.dat");

	vector<string> woerter = read_words(fname);

	cout << "Anzahl der Wörter: " << word_counter(woerter) << endl;
	cout << "Anzahl der Buchstaben: " << letters_counter(woerter) << endl;
	cout << "Länge des längsten Wortes: " << longest_word(woerter) << endl;
	cout << "Länge des kürzesten Wortes: " << shortest_word(woerter) << endl;
	cout << "Anfangsbuchstaben der Worte: " << endl;
	start_letters_out(start_letter_counter(woerter));

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

vector<int> start_letter_counter(vector<string> words){
	vector<int> start_letters_counter(26, 0);

	for(size_t i = 0; i < words.size(); i++){
		char lower = tolower(words[i][0]);
		start_letters_counter[lower - 'a'] = start_letters_counter[lower - 'a'] + 1;
	}
	return start_letters_counter;
}

void start_letters_out(vector<int> counter){
	for(int i = 0; i < 25; i = i+5){
		cout << (char)(i+65) << ": " << counter[i] << "   " << (char)(i+66) << ": " << counter[i+1] << "   " << (char)(i+67) << ": " << counter[i+2] << "   " << (char)(i+68) << ": " << counter[i+3] << "   " << (char)(i+69) << ": " << counter[i+4] << endl;
	}
	cout << (char)(90) << ": " << counter[25] << endl;
}
