#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T max(T arr[], int size){
	T max_value = arr[0];
	for(int i = 0; i < size; ++i){
		if (arr[i] > max_value){
			max_value = arr[i];
		}
	}
	return max_value;
}

int main(){
	int numbers[] = {3, 7, 2, 9, 5};
	cout << "Max int: " << max(numbers, 5) << endl;

	const char* words[] = {"abc", "xyz", "def"};
	cout << "Max words: " << max(words, 3) << endl;
}
