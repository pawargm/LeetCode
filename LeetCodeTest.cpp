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


    bool canJump(vector<int>& nums) {
        
        int i;
        
        if(nums.size()==0)
            return false;
        
        if(nums[0]==0 && nums.size()==1)
            return true;
        if(nums[0]==0 && nums.size()>1)
            return false;
        
        for(i=0; i<nums.size(); i++) {
            
            if(nums[i]==0)
                break;
        }
        
        if(i==nums.size())
            return true;
        
        vector<int> indexVec(nums.size(),0);
        
        indexVec[0] = 1;
        
        for(i=0; i<nums.size(); i++)
        {
            if(i==0) {
                
               
                if (i+nums[i] >= nums.size()) {
                    for(int j=i+1;j<nums.size(); j++) {
                        indexVec[j] = 1;
                    }
                }
                else {
                    for(int j=i+1;j<=i+nums[i]; j++) {
                    indexVec[j] = 1;
                    }
                }
            }
            else {
                
                if(nums[i]>=nums[i-1]) {
                    
                    
                     if (i+nums[i] >= nums.size()) {
                         for(int j=i+1;j<nums.size(); j++) {
                             indexVec[j] =1;
                         }
                     }
                     else {
                        for(int j=i+1;j<=i+nums[i]; j++) {
                             indexVec[j] = 1;
                        }
                     }
                }
                
            }
        }
        
        for( i=0; i<indexVec.size(); i++) {
            if(indexVec[i] == 0)
                break;
        }
        if(i != indexVec.size()) {
            return false;
        }
        return true;
    }

        int dfsArray (vector<vector<int>>&grid, int row, int col, vector<vector<int>>&vis) {
        
        int top = 0;
        int front = 0;
        int back = 0;
        int bottom = 0;
        if (row<0 || col<0 || row>grid.size() || col>grid[0].size())
            return 0;
        
        if (vis[row][col] == 1)
            return 0;
        
        if (grid[row][col] == 1) {
            vis[row][col] = 1;
            top = dfsArray(grid, row-1, col, vis);
            bottom = dfsArray(grid, row+1, col, vis);
            back = dfsArray(grid, row, col-1, vis);
            front = dfsArray(grid, row, col+1, vis);
			return top + bottom + back + front + 1
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int maxCnt = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                
                int tmpMax = 0;         
                if(grid[i][j] == 1) {
                    tmpMax =  dfsArray(grid, i, j, vis);
                }
                if(tmpMax > maxCnt) {
                    maxCnt = tmpMax;
                }
            }
        }
        
        return maxCnt;
        
    }

   int clusterIsland (vector<vector<char>>&grid, int row, int col, vector<vector<int>>&vis) {

        if (row<0 || col<0 || row>grid.size()-1 || col>grid[0].size()-1)
            return 0;
        
        if (vis[row][col] == 1)
            return 0;
        
        if (grid[row][col] == '1') {

            vis[row][col] = 1;
            clusterIsland(grid, row-1, col, vis);
            clusterIsland(grid, row+1, col, vis);
            clusterIsland(grid, row, col-1, vis);
            clusterIsland(grid, row, col+1, vis);
        }
		int tmp=0;
        return 0;
    }
    
    int numIslands(vector<vector<char>>& grid) {
    
                
        if(grid.size() == 0)
            return 0;
        
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int cntIsland = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                             
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    clusterIsland(grid, i, j, vis);
                    cntIsland++;
                }
            }
        }
        return cntIsland;
        
    }


        public boolean dfsRetry(char[][] board, int row, int col, String word, int currCnt, int [][]visit) {
        
        
        if(board[row][col] == word.charAt(currCnt) && (currCnt+1) == word.length())
            return true;
        if(board[row][col] != word.charAt(currCnt) && (currCnt+1) == word.length())
            return false;
        
        int rowLen = board.length;
        int colLen = board[0].length;

        boolean upper, lower, left, right;
        //upper
        if( (row-1)>=0 && (board[row-1][col] == word.charAt(currCnt)) && visit[row-1][col] == 0) {
            visit[row-1][col] = 1;
            upper = dfsRetry(board, row-1, col, word, currCnt+1, visit);
        } else {
            upper = false;
        }
        //lower
        if((row+1) < rowLen &&(board[row+1][col] == word.charAt(currCnt)) && visit[row+1][col] == 0 )  {
            visit[row+1][col] = 1;
            lower = dfsRetry(board, row+1, col, word, currCnt+1, visit);
        } else {
            lower = false;
        }
        //right
        if((col+1) < colLen &&(board[row][col+1] == word.charAt(currCnt)) && visit[row][col+1] == 0 )  {
            visit[row][col+1] = 1;
            right = dfsRetry(board, row, col+1, word, currCnt+1, visit);
        } else {
            right = false;
        }
        //left
        if((col-1) >=0 &&(board[row][col-1] == word.charAt(currCnt)) && visit[row][col-1] == 0 )  {
            visit[row][col-1] = 1;
            left = dfsRetry(board, row, col-1, word, currCnt+1, visit);   
        } else {
            left = false;
        }
        
        boolean res = upper || lower || left || right;
        
        return res;
    }
    
    
    
    
    public boolean exist(char[][] board, String word) {
        
        
        boolean res = false;
        for(int i=0; i<board.length; i++) {
            
            for(int j=0; j<board[0].length; j++) {
                
                int [] []visit = new int[board.length][board[0].length];
                
                if(board[i][j] == word.charAt(0)) {
                    visit[i][j] = 1;
                    res = dfsRetry(board, i, j, word,0,visit);
                }
                if(res == true)
                    break;
            }
            if(res == true)
                break;
        }
        return res;
    }



    
};
int main() {


	Solution sobj;

  //[4,5,6,7,0,1,2]
//  vector<int> vec;
  
 // vec.push_back(1);
 // vec.push_back(0);
 // vec.push_back(1);
 // vec.push_back(1);
  //vec.push_back(6);
  //vec.push_back(4);
  //vec.push_back(1);
  //vec.push_back(1);

  //vector<int> vec1;
  //vec1.push_back(1);
  //vec1.push_back(1);

  //int res = sobj.search(vec, 0);
  //cout<<"Result is : "<<res<<endl;
  //bool tmp = sobj.canJump(vec);
  //cout<<"output: "<<tmp<<endl;i

	vector<vector<char>> grid {
								{'1','1','1','1','0'},
								{'1','1','0','1','0'},
								{'1','1','0','0','0'},
								{'0','0','0','0','0'}
							};

	int res = sobj.numIslands(grid);
	cout<<"Max isLand: "<<res<<endl;
	return 0;
}
