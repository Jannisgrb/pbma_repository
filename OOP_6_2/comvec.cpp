#include "CommonVector.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    CommonVector<int, 10> squares;
    for (size_t i = 0; i < squares.size(); ++i)
    {
        squares[i] = i * i;
    }
    squares.out();
   
    string text = "Hallo tolle C++ Welt";
    
    CommonVector<char, 25> chars;
    for (size_t i = 0; i < chars.size(); ++i)
    {
        if (i < text.size())
        {
            chars[i] = text[i];
        }
        else
        {
            chars[i] = 0; 
        }
    }
    chars.out();

    CommonVector<char*, 4> words;
    words[0] = (char*)"Hallo";
    words[1] = (char*)"tolle";
    words[2] = (char*)"C++";
    words[3] = (char*)"Welt";
    
    cout << "[ ";
    for (size_t i = 0; i < words.size(); ++i)
    {
        cout << words[i] << " ";
    }
    cout << "]" << endl;
    
}
