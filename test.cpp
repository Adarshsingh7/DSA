#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int heapHeight(int N, int arr[]){
        // code here
        int times = 0;
        while(N!=1) {
            times++;
            N=N>>1;
        }
        return times;
    }
};
void print(vector<int>&v) {
    for(int el:v) cout<<el<<" ";
    cout<<endl;
}
int main () {
    vector<int> v({2, 4, 6, 7, 8});
    print(v);
    cout<<v.front();
}
