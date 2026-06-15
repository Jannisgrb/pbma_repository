#include "Sequence.h"
#include "pbma.h"
#include <iostream>
using namespace std;

Sequence<studi> search_matr(Sequence<studi> studis, int search_matr) {
	Sequence<studi> results;
	for (size_t i = 0; i < studis.size(); ++i) {
		if (studis[i].get_matr() == search_matr) {
			results.push_back(studis[i]);
		}
	}
	return results;
}

Sequence<studi> search_vn(Sequence<studi> studis, string search_vn) {
	Sequence<studi> results;
	for (size_t i = 0; i < studis.size(); ++i) {
		if (studis[i].get_vn().find(search_vn) != string::npos) {
			results.push_back(studis[i]);
		}
	}
	return results;

}

Sequence<studi> search_nn(Sequence<studi> studis, string search_nn) {
	Sequence<studi> results;
	for (size_t i = 0; i < studis.size(); ++i) {
		if (studis[i].get_nn().find(search_nn) != string::npos) {
			results.push_back(studis[i]);
		}
	}
	return results;

}

Sequence<studi> search_studi(Sequence<studi> studis, string search_matr,
		string search_vn, string search_nn) {
	Sequence<studi> results;
	for (size_t i = 0; i < studis.size(); ++i) {
		bool nn_ok = search_nn.empty()
				|| (studis[i].get_nn().find(search_nn) != string::npos);
		bool vn_ok = search_vn.empty()
				|| (studis[i].get_vn().find(search_vn) != string::npos);
		bool matr_ok = search_matr.empty()
				|| (studis[i].get_matr() == stoi(search_matr));

		if (matr_ok && vn_ok && nn_ok) {
			results.push_back(studis[i]);
		}
	}
	return results;
}

int main(int argc, const char *argv[]) {
	args_t args(argc, argv);
	string fname = args.pos(0, "studis.txt");

	vector<string> lines = read_words(fname);

	Sequence<studi> studis;
	for (size_t i = 0; i < lines.size(); i += 3) {
		studi s;
		s.set_matr() = stoi(lines[i]);
		s.set_vn() = lines[i + 1];
		s.set_nn() = lines[i + 2];

		studis.push_back(s);
	}

	string matr_wanted = "";
	string vn_wanted = "";
	string nn_wanted = "";

	if (args.has_option("m"))
		matr_wanted = args.option("m");
	if (args.has_option("v"))
		vn_wanted = args.option("v");
	if (args.has_option("n"))
		nn_wanted = args.option("n");

	Sequence<studi> Result = search_studi(studis, matr_wanted, vn_wanted, nn_wanted);

	for(size_t i = 0; i < Result.size(); ++i){
		Result[i].out();
	}

//	if (args.has_option("m")) {
//		string matr_wanted = args.option("m");
//		if (!matr_wanted.empty()) {
//			Sequence<studi> Result = search_matr(studis, stoi(matr_wanted));
//			for (size_t i = 0; i < Result.size(); ++i) {
//				Result[i].out();
//			}
//		}
//	}
//
//	if (args.has_option("v")) {
//		string vn_wanted = args.option("v");
//		if (!vn_wanted.empty()) {
//			Sequence<studi> Result = search_vn(studis, vn_wanted);
//			for (size_t i = 0; i < Result.size(); ++i) {
//				Result[i].out();
//			}
//		}
//	}
//
//	if (args.has_option("n")) {
//			string nn_wanted = args.option("n");
//			if (!nn_wanted.empty()) {
//				Sequence<studi> Result = search_nn(studis, nn_wanted);
//				for (size_t i = 0; i < Result.size(); ++i) {
//					Result[i].out();
//				}
//			}
//		}
}
