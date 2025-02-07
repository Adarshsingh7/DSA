#include <bits/stdc++.h>

using namespace std;

class Store {
public:
    int row;
    int col;
    int val;
    Store(int row, int col, int val) : row(row), col(col), val(val) {}
};

class Compare {
public:
    bool operator() (const Store& a, const Store& b) const {
        return a.val > b.val; // Min heap based on `val`
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Store, vector<Store>, Compare>pq;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            int el = nums[i][0];
            pq.emplace(i, 0, el);
            mini = min(mini, el);
            maxi = max(maxi, el);
        }

        int ansStart = mini;
        int ansEnd = maxi;
        int diff = ansEnd - ansStart;

        while(!pq.empty()) {
            Store top = pq.top();
            pq.pop();

            if(top.col+1 < nums[top.row].size()) {
                int newEl = nums[top.row][top.col+1];
                pq.emplace(top.row, top.col+1, newEl);
                mini = min(mini, newEl);
                maxi = max(maxi, newEl);
                if(maxi-mini < diff) {
                    diff = maxi-mini;
                    ansStart = mini;
                    ansEnd = maxi;
                }
            }
        }
        return {ansStart, ansEnd};
    }
};
