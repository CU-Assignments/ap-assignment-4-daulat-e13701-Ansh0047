#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(n--){
            nums1.pop_back();
        }
        for(auto it:nums2){
            nums1.push_back(it);
        }
        sort(nums1.begin(),nums1.end());
    }
};