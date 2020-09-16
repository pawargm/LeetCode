#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<map>
#include<vector>
#include<algorithm>

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

vector<vector<int>> isThreeSum(vector<int> &arr) {

	sort(arr.begin(), arr.end());
	vector<vector<int>> res;
	for(int k = arr.size()-1; k>=2; k--) {

		int i = 0;
		int j = k-1;
		vector<int> tmp;
		while(i<j) {

			if(arr[i] + arr[j] + arr[k] == 0) {
				//cout<<"Triplet at Index ith " <<i<<"jth "<<j<<" kth "<<k<<"\n"<<endl;
				tmp.push_back(arr[i]);
				tmp.push_back(arr[j]);
				tmp.push_back(arr[k]);
				res.push_back(tmp);
			}
			if(arr[i] + arr[j] + arr[k] < 0)
				i++;
			else
				j--;
		}
	}
	return res;
}

int main() {

	vector<int> arr;
	// 12, 11, 13, 5, 6, 7
	arr.push_back(-1);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(-1);
	arr.push_back(-4);

//	sort(arr.begin(), arr.begin()+3);

//	tst(arr);
//	int cnt = 0;
//	mergeSort(arr, 0, 5, &cnt);
	
//	int tst = 0;
//	printf("Minimum Swap is %d\n", cnt);
	vector<vector<int>>res  = isThreeSum(arr);
	int y =0;
	return 0;
}
