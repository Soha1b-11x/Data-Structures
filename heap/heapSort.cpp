#include <iostream>
using namespace std;
 
void Heapify(int arr[] , int idx , int n){
    int largest = idx;
    int left = 2*idx+1;
    int right = 2*idx+2;

    if(left<n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right<n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != idx){
        swap(arr[largest],arr[idx]);
        Heapify(arr , largest , n);
    }
}

void createMaxHeap(int arr[] , int n){
    //step up approach
    for(int i=(n-1)/2 ; i>=0 ;i--){
        Heapify(arr , i , n);
    }
}

void print(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapSort(int arr[] , int n){
    int size = n;
    swap(arr[0],arr[size-1]);
    size--;
    Heapify(arr , 0 , size);
    print(arr , size);
    if(size > 0) heapSort(arr , size);
}

int main(){
    // steps in heap sort
    // convert array into max heap
    // replace first element with last 
    // decrease size by 1
    // apply Heapify
    // repet unit arr size 0

    int arr[]={10,11,14,8,3,19,12};
    createMaxHeap(arr , 7);
    print(arr , 7);
    heapSort(arr , 7);
    print(arr , 7);

    // Build Max Heap: O(n)
    // Heap Sort: O(n log n)
    // Overall: O(n log n)
    // Extra space: O(log n) because your heapSort() and Heapify() are recursive.
}