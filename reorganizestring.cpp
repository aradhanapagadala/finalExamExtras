#include <iostream>
using namespace std;
#include <queue>
#include <unordered_map>
// difficulty level: medium
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for (int i = 0; i < n; i++)
            freq[s[i]]++;

        priority_queue<pair<int, char>> pq;
        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c] > 0) {
                pq.push({ freq[c], c });
            }
        }

        string res = "";

        pair<int, char> prev = { -1, '#' };

        while (!pq.empty()) {
        

            pair<int, char> p = pq.top();
            pq.pop();
        
            res.push_back(p.second);

            if (prev.first > 0)
                pq.push(prev);

            p.first--;
            prev = p;
    }

        if (res.size() != n)
            return "";
            return res;
        }

};
