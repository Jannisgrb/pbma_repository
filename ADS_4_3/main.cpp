
#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

void HeapSort(vector<int> &list);
void bubble_up(vector<int> &baum, int i);
void bubble_down(vector<int> &baum, int n);

int main() {
	check_sort(HeapSort, true, true);
}

void HeapSort(vector<int> &list) {
	vector<int> baum(list.size() + 1);
	baum[1] = list[0];
	for (size_t i = 0; i < list.size(); i++) {
		int akt_index = i + 1;
		baum[akt_index] = list[i];
		bubble_up(baum, akt_index);
	}

	for (size_t i = 0; i < list.size(); i++){
		list[i] = baum[1];
		int last_index = list.size() - i;
		baum[1] = baum[last_index];
		bubble_down(baum, last_index - 1);
	}
}

void bubble_up(vector<int> &baum, int i) {
	while(i > 1 && baum[i/2] > baum[i]){
		swap(baum[i], baum [i/2]);
		i = i / 2;
	}
}

void bubble_down(vector<int> &baum, int n) {
	int i = 1;
	while(2*i <= n){
		int child = 2*i;

		if(child + 1 <= n && baum[child+1] < baum[child]){
			child++;
		}

		if(baum[child] < baum[i]){
			swap(baum[i], baum[child]);
			i = child;
		}else {
			break;
		}
	}
}
