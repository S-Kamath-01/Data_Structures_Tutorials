#include<iostream>
using namespace std;

int main(){
    int num = 5;
    cout<< num << endl;
    // address of operator - &
    cout<<"Address of operator is "<<&num<<endl;
    int *ptr = & num;
    cout<<"Value is:"<<*ptr<<endl;
    cout<<"Address is:"<<ptr<<endl;
    double d = 4.3;
    double *p2 = &d;
    cout<<"Value is:"<<*p2<<endl;
    cout<<"Address is:"<<p2<<endl;
    cout<<"Size of integer is "<<sizeof(num)<<endl;
    cout<<"Size of pointer is "<<sizeof(ptr)<<endl;
    cout<<"Size of pointer 2 is "<<sizeof(p2)<<endl;
    // the size of the pointer was supposed to be 8 bits as this is a 64 bit system but it prints as 4 bytes as the compiler is a 32 bit compiler mingw32
    // Note that pointer size is 4 bytes on a 32 bit system and 8 bytes in a 64 bit system but the compiler matters

    (*ptr)++;
    cout<<num<<endl;
    // it is the same as num++
    //* is the dereference operator and *ptpor means the value at address pointed by ptr
    cout<<*ptr<<endl;

    return 0;
    
}