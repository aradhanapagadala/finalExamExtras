#include <iostream>
#include <vector>
#include <set>
using namespace std;
// difficulty level: easy
class Solution {
public:
    int sumDigitSquare(int n)
    {
        int sq = 0;
        while (n) {
            int digit = n % 10;
            sq += digit * digit;
            n = n / 10;
        }
        return sq;
    }
    bool isHappy(int n) {
            // A set to store numbers during
    // repeated square sum process
        set<int> s;
        s.insert(n);


        while (1) {

        // Number is Happy if we reach 1
            if (n == 1)
                return true;

        // Replace n with sum of squares
        // of digits
            n = sumDigitSquare(n);

        // If n is already visited, a cycle
        // is formed, means not Happy
            if (s.find(n) != s.end())
                return false;

        // Mark n as visited
            s.insert(n);
        }

        return false;
    }
};