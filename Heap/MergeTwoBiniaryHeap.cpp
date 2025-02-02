#include "Heap.h"

using namespace std;

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>v(m+n);
        int i=0;
        for(int el:a) v[i++] = el;
        for(int el:b) v[i++] = el;
        // make_heap(v.begin(), v.end());
        // return v;
        Heap h(v);
        return h.getHeap();
    }
};
