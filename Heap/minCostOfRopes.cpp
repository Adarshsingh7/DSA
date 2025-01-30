#include <bits/stdc++.h>
#include "Heap.h"

using namespace std;

class Solution {
  public:
  // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        Heap h(arr);
        int sum = 0;

        while(h.size()!=1) {
            int fi = h.top(); h.pop();
            int sec = h.top(); h.pop();

            h.push(fi+sec);
            sum+=fi+sec;
        }
        return sum;
    }
};
