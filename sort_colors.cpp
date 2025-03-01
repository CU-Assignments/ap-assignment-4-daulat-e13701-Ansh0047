#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algo 
        // TC = O(n) SC = O(1)
        int n = nums.size();
        int zeroIndex = 0, twoIndex = n-1;

        int i=0;
        while(i <= twoIndex){
            if(nums[i] == 1){
                i++;
            }
            else if(nums[i] == 0){
                swap(nums[i],nums[zeroIndex]);
                zeroIndex++;
                i++;
            }
            else{
                swap(nums[i],nums[twoIndex]);
                twoIndex--;
            }
        }
    }
};