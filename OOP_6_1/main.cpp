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

class myString{
	private:
		char* str;
	public:
		myString(char* s = "") : str(s) {}
		const char* getStr() const {
			return str;
		}
		bool operator>(const myString& other) const {
			return strcmp(this->str, other.str) > 0;
		}
};

int main(){
	int numbers[] = {3, 7, 2, 9, 5};
	cout << "Max int: " << max(numbers, 5) << endl;

	const char* words[] = {"abc", "xyz", "def"};
	cout << "Max words: " << max(words, 3) << endl;

	myString custom_words[] = { myString("abc"), myString("xyz"), myString("def") };
    
    myString max_word = max(custom_words, 3);
    cout << "Max myString: " << max_word.getStr() << endl; // Gibt "xyz" aus
}
