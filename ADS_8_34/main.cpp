#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

bool vis_add(vector<int> &vis, int ele) {
	for (size_t i = 0; i < vis.size(); ++i) {
		if (ele == vis[i]) {
			return false;
		}
	}

	vis.push_back(ele);
	return true;
}

bool vis_contains(vector<int> &vis, int ele) {
	for (size_t i = 0; i < vis.size(); ++i) {
		if (ele == vis[i]) {
			return true;
		}
	}
	return false;
}

bool vis_remove(vector<int> &vis, int ele) {
	for (size_t i = 0; i < vis.size(); ++i) {
		if (ele == vis[i]) {
			vis.erase(vis.begin() + i);
			return true;
		}
	}
	return false;
}

int main() {
	vector<int> numbers = create_same_randints(10000, 1, 3000);
	vector<int> vis;

	for (size_t i = 0; i < 5000; ++i) {
		vis_add(vis, numbers[i]);
	}

	for (size_t i = 5000; i < 10000; ++i) {
		vis_remove(vis, numbers[i]);
	}

	cout << vis.size() << endl;

}
