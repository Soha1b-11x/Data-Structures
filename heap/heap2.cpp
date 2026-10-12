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
    //step down approach
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

int main(){
    int arr[]={15,65,48,51,64,25,42,27,51,51};
    createMaxHeap(arr , 10);
    print(arr , 10);
}