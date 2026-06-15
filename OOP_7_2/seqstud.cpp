#include "Sequence.h"
#include "pbma.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]){
    args_t args(argc, argv);
    string fname = args.pos(0, "studis.txt");

    vector<string> lines = read_lines(fname);

    Sequence<studi> studis;
    for(size_t i = 0; i < lines.size(); i += 3){
        studi s;
        s.matrikelnummer = lines[i];
        s.vorname = lines[i + 1];
        s.nachname = lines[i + 2];

        studis.push_back(s);
    }
}