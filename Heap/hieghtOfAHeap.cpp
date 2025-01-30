#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int heapHeight(int N, int arr[]){
        if(N==1) return 1;
        // code here
        int times = 0;
        while(N!=1) {
            times++;
            N=N>>1;
        }
        return times;
    }
};
