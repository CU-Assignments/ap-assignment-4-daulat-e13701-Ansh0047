#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // idea is : if mid is on an incresing slope the peak must be on the right
        // if mid is on the decreasing slope the peak must be on the left
        // takecare of edge case for 0th and n-1th element
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1, high = n-2;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }

            // mid on increasing slope -- then peak must be on the right else on the left
            if(nums[mid] < nums[mid+1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;
    }
};