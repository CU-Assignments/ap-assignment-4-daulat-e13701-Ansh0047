#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        // using kadanes algo ==> TC = O(n)   
        // PTR is -ve sum is of no use so we will not go with it further make it 0
        int sum = 0, maxSum = INT_MIN;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum < 0) sum = 0;
        }

        return maxSum;
        */

        // using dp => we will check for the prev sum if (nums[i] + prevSum[i-1]) > nums[i] then will take it 
        // else nums[i] will be the maxSum bcoz we will be maximizing my sum in long run

        int n = nums.size();
        vector<int>dp(n);

        dp[0] = nums[0];

        for(int i=1;i<n;i++){
            if(nums[i] + dp[i-1] > nums[i]){
                dp[i] = dp[i-1] + nums[i];
            }
            else{
                dp[i] = nums[i];
            }
        }

        int maxSum = INT_MIN;
        for(auto it:dp) maxSum = max(it,maxSum);
        return maxSum;

    }
};