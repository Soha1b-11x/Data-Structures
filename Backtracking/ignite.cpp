#include <iostream>
#include <vector>
using namespace std;

void solve(int A,int B,int C, vector<string>&arr, string& s){
    if(A==0 && B==0 && C==0){
        arr.push_back(s);
        return;
    }

    if(A>0){
        s.push_back('A');
    solve(A-1,B,C,arr,s);
    s.pop_back();
    }

    if(B>0){
        s.push_back('B');
    solve(A,B-1,C,arr,s);
    s.pop_back();
    }

    if(C>0){
        s.push_back('C');
    solve(A,B,C-1,arr,s);
    s.pop_back();
    }
    
}

int main(){
    int A=1,B=3,C=2;
    vector<string>arr;
    string s = "";
    solve(A,B,C,arr,s);

    for (int i = 0; i < arr.size(); i++)
    {
        /* code */
        cout<<arr[i]<<"  ";
    }
    
    return 0;
}