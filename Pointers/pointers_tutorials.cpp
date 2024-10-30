#include<iostream>
using namespace std;

int main(){
    int num = 5;
    cout<< num << endl;
    // address of operator - &
    cout<<"address of operator is "<<&num<<endl;
    int *ptr = & num;
    (*ptr)++;
    cout<<num<<endl;
    // it is the same as num++
    //* is the dereference operator and *ptr means the value at address pointed by ptr
    cout<<*ptr<<endl;
    return 0;
    
}