#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N){
        // replace with the rank
        vector<int> ans(N);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // heap <element, rank>
        for(int i=0; i<N; i++) {
            pq.emplace(arr[i], i);
        }
        int rank = 0;
        int prev = -1;
        for(int i=0; i<N; i++) {
            pair<int, int> top = pq.top(); pq.pop();
            rank = (prev == top.first) ? rank : rank + 1;
            ans[top.second] = rank;
            prev = top.first;
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> arr({2, 20, 10, 3, 14, 16, 14});
    vector<int>ans(s1.replaceWithRank(arr, arr.size()));
    for(auto el: ans) cout<<el<<" ";
    return 0;
}
