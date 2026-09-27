#include <bits/stdc++.h>
using namespace std;

int i=0;

void printNums(int &n){
    if(i>n) return;
    cout<< i <<" ";
    i++;
    printNums(n);
}

int main(){
    cout<<"Enter N : ";
    int n;
    cin>>n;
    printNums(n);
}