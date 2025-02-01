#include "Heap.h"
#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Heap heap(nums);

        for(int i=0; i<k-1; i++) heap.pop();
        return heap.pop();
    }
};

// approch 2 more optimized approch
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<k; i++) pq.push(nums[i]);

        for(int i=k; i<nums.size(); i++) {
            if(pq.top()<nums[i]) {
                pq.push(nums[i]);
                pq.pop();
            }
        }

        return pq.top();
    }
};
