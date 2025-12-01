#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            // Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
  
        // Return K'th largest element
        return nums[k - 1];
        }
};