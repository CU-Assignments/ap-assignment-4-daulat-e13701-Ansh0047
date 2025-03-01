#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> solve1(vector<int>& nums, int k){
        int n = nums.size();
        map<int,int>mp;
        for(auto it:nums) mp[it]++;

        priority_queue<pair<int,int>>pq;
        for(auto [e,f]:mp) pq.push({f,e});

        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

        // TC = O(n*log(n) + k*log(n)) , SC = O(n + n)
        // try to remove the storing of numbers in map
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // return solve1(nums,k);

        // to remove the map store, we can sort the arryay and check where the elements diff
        // and add the contribution of each unique element as i-start

        int n = nums.size();
        sort(begin(nums),end(nums));

        vector<pair<int,int>>store;
        int start = 0;

        for(int i=1;i<n;i++){   
            if(nums[i] != nums[i-1]){
                store.push_back({i-start,nums[start]});
                start = i;
            }
        }

        store.push_back({n-start,nums[start]});
        sort(rbegin(store),rend(store));

        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(store[i].second);
        }

        return ans;
        // TC = O(n*log(n) + m*log(m) + k) SC = O(m)
        // remove the storing the elements in map
    }
};