#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
     
        int sizet = nums.size();
        
        vector<vector<int> > resvec ;
        vector<int> vectmp;
        
        resvec.push_back(vectmp);
        
        for(int i=0; i<sizet; i++) {
            int sizep = resvec.size();
            for(int j=0; j<sizep; j++) {
                
                vector<int> subset = resvec[j];
                subset.push_back(nums[i]);
                resvec.push_back(subset);
            }
            
        }
        return resvec;
    }
    int isTheir(vector<int>& nums, int start, int end, int target) {
    
       int mid = start + (end-start)/2;
       int res = -1;
       
       if(start>end){
           return -1;
       }
       
       if(target== nums[mid])
           return mid;
       
       //If start .. mid is sorted 
       if(nums[start] <= nums[mid]) {
           
           if(target>=nums[start] && target<=nums[mid]){
               return isTheir(nums, start, mid-1, target);
           }
           return isTheir(nums,mid+1,end,target);
       }
       //If target lies in mid .. end
       if(target<=nums[end] && target>=nums[mid]) {
           return isTheir(nums,mid+1,end,target);
       }
       return isTheir(nums,start,mid-1,target);
  }
    
  int search(vector<int>& nums, int target) {
        
      return isTheir(nums,0,nums.size()-1,target);
        
  }

    int maxProfit(vector<int>& prices) {
        
        
        queue<int> que;
        
        que.push(prices[0]);
        
        int max_profit = 0;
        
        for(int i=1; i<prices.size(); i++) {
            
            if( que.back() > prices[i] ) {
                
                if ( prices[i] < que.front() ) {
                    
                    if(que.size()>1) {
                        
                        int tmp = que.back() - que.front();
                        
                        if( tmp > max_profit ) {
                            max_profit = tmp;
                        }
                        
                    }
                    //just skipped for que.size()<1
                    while(!que.empty()) {
                        que.pop();
                    }
                    que.push(prices[i]);
                }
                //just skipped 
            }
            else {
               que.push(prices[i]); 
            }  
        }
        
        int tmp2 = que.back() - que.front();
        
        if(tmp2 > max_profit) {
            max_profit=tmp2;
        }
        return max_profit;
    }


      double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int sizeNum1 = nums1.size();
        int sizeNum2 = nums2.size();
        int totalSize = sizeNum1 + sizeNum2;
        int halfNum = 0;
        int halfNumLessOne = 0;
        int indexNum1 = 0;
        int indexNum2 = 0;
		int cnt = -1;
        
        
        if(sizeNum1 == 0 && sizeNum2 == 0) {
            return 0;
        }
        
        if(sizeNum1 == 0) {
            
            if(sizeNum2%2 == 0) {
                return (nums2[sizeNum2/2] + nums2[sizeNum2/2]-1)/2;
            }
            else {
                return nums2[sizeNum2/2];
            }
        }
        if(sizeNum2 == 0) {
            
            if(sizeNum1%2 == 0) {
                return (double) (nums1[sizeNum1/2] + nums1[sizeNum1/2]-1)/2;
            }
            else {
                return nums1[sizeNum1/2];
            }
        }
        
        while(halfNum == 0) {

			int num = 0;
			if(indexNum1<sizeNum1 && indexNum2 <sizeNum2) {
            	if (nums1[indexNum1] <= nums2[indexNum2]) {
                	num = nums1[indexNum1];
					indexNum1++;
            	}
            	else {
					num = nums2[indexNum2];
                	indexNum2++;
            	}
			}
			else {
				if( indexNum1 == sizeNum1 && indexNum2 < sizeNum2) {
					num = nums2[indexNum2];
					indexNum2++;
				}
				if( indexNum2 == sizeNum2 && indexNum1 < sizeNum1) {
					num = nums1[indexNum1];
					indexNum1++;
				}
			}
            cnt++;
            if (cnt == ((totalSize/2)-1) ) {
				halfNumLessOne = num;
            }
            if (cnt == (totalSize/2)) {
				halfNum = num;
           }   
        }
        
        if(totalSize%2 == 0) {
            return (double)(halfNum+halfNumLessOne)/2; 
        }
        return halfNum;   
    }




    
};
int main() {


	Solution sobj;

  //[4,5,6,7,0,1,2]
  vector<int> vec;
  
  vec.push_back(1);
  vec.push_back(2);
  //vec.push_back(5);
  //vec.push_back(3);
  //vec.push_back(6);
  //vec.push_back(4);
  //vec.push_back(1);
  //vec.push_back(1);

  vector<int> vec1;
  vec1.push_back(3);
  vec1.push_back(4);

  //int res = sobj.search(vec, 0);
  //cout<<"Result is : "<<res<<endl;
  double tmp = sobj.findMedianSortedArrays(vec, vec1);
  cout<<"Max Profit: "<<tmp<<endl;
	return 0;
}
