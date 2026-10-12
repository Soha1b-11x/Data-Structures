#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[] , int idx , int n){
    int left = 2*idx+1;
    int right = 2*idx+2;
    int max = idx;

    if(left<n && arr[left] > arr[max]){
        max = left;
    }
    if(right<n && arr[right] > arr[max]){
        max = right;
    }

    if(max != idx){
        swap(arr[max],arr[idx]);
        Heapify(arr , max, n);
    }
}

void createHeap(int arr[] , int n){
    int lastParentidx = n-1/2;
    //step down appraoch
    for(int i=lastParentidx;i>=0;i--){
        Heapify(arr , i , n);
    }
}

void mergeHeap(int arr[] , int arr2[] , int n , int m){
    int mergerArray[n+m];
    int index = 0; int size = n+m;

    for(int i=0;i<n;i++){
        mergerArray[index] = arr[i];
        index++;
    }
    for(int i=0;i<m;i++){
        mergerArray[index] = arr2[i];
        index++;
    }

    //print
    cout <<"Before create heap ";
    for(int i=0;i<size;i++){
        cout<<mergerArray[i]<<" ";
    }
    cout<<endl;

    createHeap(mergerArray , size);

    //print
    cout <<"After create heap ";
    for(int i=0;i<size;i++){
        cout<<mergerArray[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {4,3,5};
    int arr2[] = {7,2,6};
    int n=3,m=3;

    mergeHeap(arr , arr2 ,n ,m);

    return 0;
}