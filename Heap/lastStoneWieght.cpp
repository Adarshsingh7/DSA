#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()>1) {
            int fi = pq.top(); pq.pop();
            int sec = pq.top(); pq.pop();
            int sum = abs(fi-sec);
            if(sum) pq.push(sum);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
