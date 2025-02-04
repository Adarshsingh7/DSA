#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
private:
    // Max-heap to store the smaller half of the numbers
    priority_queue<int> maxi;
    // Min-heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> mini;
    double median = 0;
public:
    MedianFinder() {
        // Constructor
    }

    void addNum(int num) {
        // Add number to the appropriate heap
        if(maxi.size() == 0 || num < maxi.top())
            maxi.push(num);
        else
            mini.push(num);

        // Balance the heaps if necessary
        if(maxi.size() > mini.size() + 1) {
            mini.push(maxi.top());
            maxi.pop();
        }
        if(mini.size() > maxi.size() + 1) {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian() {
        // If both heaps are of the same size, the median is the average of the two middle elements
        if(maxi.size() == mini.size())
            return (maxi.top() + mini.top()) / 2.0;
        // If max-heap has more elements, the median is the top of max-heap
        else if(maxi.size() > mini.size())
            return maxi.top();
        // If min-heap has more elements, the median is the top of min-heap
        else
            return mini.top();
    }
};
