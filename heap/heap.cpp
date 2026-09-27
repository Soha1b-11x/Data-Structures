#include <iostream>
using namespace std;

class maxHeap{
    int * arr;
    int size; //current size mean how much element in this heap
    int total_size;

    public:

    maxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size=n;
    }

    void insert(int val){
        if(size == total_size){
            cout<<"heap over Flow"<<endl;
            return;
        }

        arr[size] = val;
        int idx = size;
        size++; 

        //compare it wirh its parrent
        while (idx > 0 && arr[(idx-1)/2] < arr[idx]){
            swap(arr[idx],arr[(idx-1)/2]);
            idx = (idx-1)/2;
        }

        cout<<arr[idx]<<" inserted into heap "<<endl;
    }

    void Delete(){
        if(size == 0){
            cout<<"Heap underflow"<<endl;
            return;
        }

        cout<<arr[0]<<" Deleted form heap "<<endl;
        arr[0] = arr[size-1];
        size--;
        if(size == 0) return;

        Heapify(0);
    }

    void Heapify(int index){
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;

        if(left<size && arr[largest] < arr[left]){
            largest = left;
        }
        if(right<size && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest!=index){
            swap(arr[index],arr[largest]);
            Heapify(largest);
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    maxHeap h1(6); //6 is size
    h1.insert(1);
    h1.insert(2);
    h1.insert(5);
    h1.insert(3);
    h1.insert(6);
    h1.insert(7);

    h1.print();

    h1.Delete();
    h1.print();
    return 0;
}