#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// difficulty level: medium

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {

        if (arr.empty()) return 0;

        sort(arr.begin(), arr.end());
  
    int res = 1, cnt = 1;
  
    // find the maximum length by traversing the array
        for (int i = 1; i < arr.size(); i++) {
      	
        // Skip duplicates
            if (arr[i] == arr[i-1]) 
                continue;

        // Check if the current element is equal
        // to previous element + 1
            if (arr[i] == arr[i - 1] + 1) {
                cnt++;
            } 
            else {
                cnt = 1;
            }

            res = max(res, cnt);
    }
    return res;
    }
};