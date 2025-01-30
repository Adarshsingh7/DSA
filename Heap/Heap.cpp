#include <iostream>
#include <vector>

using namespace std;

class Heap {
    private:
        vector<int> heap;
        int pos;

        void heapify(int idx) {
            int largest = idx;
            int left = (idx * 2) + 1;
            int right = (idx * 2) + 2;

            if (left < this->pos && this->heap[largest] < this->heap[left]) largest = left;
            if (right < this->pos && this->heap[largest] < this->heap[right]) largest = right;

            if (largest != idx) {
                swap(this->heap[idx], this->heap[largest]);
                heapify(largest);
            }
        }
    public:
        Heap() {
            this->pos = 0;
        }

        Heap(vector<int> v) {
            this->heap = v;
            this->pos = v.size();

            int n = this->pos / 2 - 1;

            for(int i = n; i >= 0; i--) {
                this->heapify(i);
            }
        }

        void push(int el) {
            this->heap.push_back(el);
            this->pos++;

            int i = this->pos - 1; // current element insertion pos
            while(i != 0 && this->heap[(i - 1) / 2] < this->heap[i]) {
                swap(this->heap[(i - 1) / 2], this->heap[i]);
                i = (i - 1) / 2;
            }
        }

        int pop() {
            if (this->pos == 0) return -1; // No element to delete
            int el = this->heap[0];
            // Move the last element to the root and reduce the pos
            swap(this->heap[0], this->heap[this->pos - 1]);
            this->pos--;
            // this->heap.pop_back();

            this->heapify(0);
            return el;
        }

        vector<int> heapSort () {
            while(this->pos!=0) this->pop();
            return this->heap;
        }

        int size() {
            return this->pos;
        }

        bool empty() {
            return this->pos == 0;
        }

        int top() {
            return this->heap[0];
        }

        void print() {
            for(int el : this->heap) {
                cout << el << " ";
            }
            cout << endl;
        }
};
