#include <iostream>
using namespace std;

void printName(string &name , int times){
    if(times == 5) return ;
    cout<<name <<endl;
    times++;
    printName(name , times);
}

int main(){
    string name;
    cout<<"Enter name :";
    cin>> name;

    printName(name , 0);
}