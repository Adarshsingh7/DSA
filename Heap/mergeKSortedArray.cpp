#include <bits/stdc++.h>
#include <queue>

using namespace std;
class Store {
public:
    int val;
    int i;
    int j;
    Store(int i, int j, int val) : i(i), j(j), val(val) {}

    bool operator>(const Store *st) {
        return this->val > st->val;
    }
};

class Comp {
public:
    bool operator()(Store a, Store b) {
        return a.val > b.val;
    }
};

class Solution {
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        int n = arr.size();
        priority_queue<Store, vector<Store>, Comp> pq;
        vector<int> ans;

        for(int i=0; i<n; i++) pq.emplace(i, 0, arr[0][i]);

        while(!pq.empty()) {
            Store top = pq.top();
            pq.pop();

            ans.push_back(top.val);
            pq.emplace(top.i, top.j +1, arr[top.i][top.j+1]);
        }

        return ans;
    }
};
