#include <iostream>
#include <vector>

using namespace std;

class Heap {
    private:
        vector<int> heap;
        int size;
    public:
        Heap() {
            this->size = 0;
        }

        Heap(vector<int> v) {
            this->heap = v;
            this->size = v.size();

            int n = this->size / 2 - 1;

            for(int i = n; i >= 0; i--) {
                this->heapify(i);
            }
        }

        void insertElement(int el) {
            this->heap.push_back(el);
            this->size++;

            int i = this->size - 1; // current element insertion size
            while(i != 0 && this->heap[(i - 1) / 2] < this->heap[i]) {
                swap(this->heap[(i - 1) / 2], this->heap[i]);
                i = (i - 1) / 2;
            }
        }

        void heapify(int idx) {
            int largest = idx;
            int left = (idx * 2) + 1;
            int right = (idx * 2) + 2;

            if (left < this->size && this->heap[largest] < this->heap[left]) largest = left;
            if (right < this->size && this->heap[largest] < this->heap[right]) largest = right;

            if (largest != idx) {
                swap(this->heap[idx], this->heap[largest]);
                heapify(largest);
            }
        }

        int deletion() {
            if (this->size == 0) return -1; // No element to delete
            int el = this->heap[0];
            // Move the last element to the root and reduce the size
            swap(this->heap[0], this->heap[this->size - 1]);
            this->size--;
            // this->heap.pop_back();

            this->heapify(0);
            return el;
        }

        vector<int> heapSort () {
            while(this->size!=0) this->deletion();
            return this->heap;
        }

        void print() {
            for(int el : this->heap) {
                cout << el << " ";
            }
            cout << endl;
        }
};

int main() {
    vector<int> v({45, 23, 10, 56, 90, 2});
    Heap heap(v);
    cout<<"heap sort"<<endl;
    vector<int>sorted(heap.heapSort());
    for(int el:sorted) cout<<el<<" ";
    return 0;
}
