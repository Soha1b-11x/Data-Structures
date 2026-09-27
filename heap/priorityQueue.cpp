#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int>Qmax; // max heap priority queue
    Qmax.push(10);
    Qmax.push(4);
    Qmax.push(20);
    Qmax.push(52);
    Qmax.push(2);

    while(!Qmax.empty()){
        cout<<Qmax.top()<<" ";
        Qmax.pop();
    }

    cout<<endl;

    priority_queue<int , vector<int> , greater<int>> Qmin;  // min heap priority queue
    Qmin.push(10);
    Qmin.push(4);
    Qmin.push(20);
    Qmin.push(52);
    Qmin.push(2);

    while(!Qmin.empty()){
        cout<<Qmin.top()<<" ";
        Qmin.pop();
    }
}