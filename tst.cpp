#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<map>
#include<vector>

using namespace std;


void mergeVec(vector<int>& arr, int start, int end, int *cnt) {

	int p = 0;
	if(start >= end)
		return;

	vector<int> tmpVec;
	int mid = start + (end-start)/2;
	int fIndex = start;
	int sIndex = mid+1;

	while(fIndex <= mid && sIndex <= end) {

		if(arr[fIndex] <= arr[sIndex]) {
			tmpVec.push_back(arr[fIndex]);
			fIndex++;
		} else {
			tmpVec.push_back(arr[sIndex]);
			*cnt = *cnt + 1;
			sIndex++;
		}
	}

	if(fIndex > mid && sIndex <=end) {
		while(sIndex<=end){
			tmpVec.push_back(arr[sIndex]);
			sIndex++;
		}
	}

	if(sIndex > end && fIndex <= mid) {
		while(fIndex <= mid) {
			tmpVec.push_back(arr[fIndex]);
			fIndex++;
		}
	}
	for(int i=0; i<tmpVec.size(); i++) {
		arr[start+i] = tmpVec[i];
	}
	return;
}

void mergeSort(vector<int>& arr, int start, int end, int *cnt) {

	if(start < end) {
		int mid = start + (end - start)/2;
		mergeSort(arr, start, mid, cnt);
		mergeSort(arr, mid+1, end, cnt);
		mergeVec(arr, start, end, cnt);
	}

}

void tst(vector<int>& arr) {

	for(int i=0; i<arr.size(); i++) {
		arr[i] = 1;
	}
	return;
}

int main() {

	vector<int> arr;
	// 12, 11, 13, 5, 6, 7
	arr.push_back(12);
	arr.push_back(11);
	arr.push_back(13);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);

//	tst(arr);
	int cnt = 0;
	mergeSort(arr, 0, 5, &cnt);
	
	int tst = 0;
	printf("Minimum Swap is %d\n", cnt);
	return 0;
}
