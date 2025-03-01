#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // maintain the min heap for the first k numbers 
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        // TC = O(n*log(k)), SC = O(k)
    }
};