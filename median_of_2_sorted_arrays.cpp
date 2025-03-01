#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merge;
        int i=0,j=0;
        int n = nums1.size();
        int m = nums2.size();
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }
            else{
                merge.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            merge.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            merge.push_back(nums2[j]);
            j++;
        }

        int size = merge.size();
        double med = 0;
        if(size % 2 == 1){
            med = merge[size/2];
        }
        else{
            med = (merge[size/2] + merge[size/2-1])/2.0;
        }

        return med;
    }
};