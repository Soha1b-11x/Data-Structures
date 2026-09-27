#include <bits/stdc++.h>
using namespace std;

int i=0;

void printNums(int &n){
    if(n < 1) return;
    cout<< n <<" ";
    n--;
    printNums(n);
}

int main(){
    cout<<"Enter N : ";
    int n;
    cin>>n;
    printNums(n);
}