#include<iostream>
using namespace std;

int main(){
    //pointer to int is created and is pointing to some garbage address

    // int *p;
    // cout<<*p<<endl; 
    // value printed as 1528349827 which makes no sense and is a garbage value

    // int i = 5;
    // int *q = &i;
    // int *p = 0;
    // p = &i;
    // cout<<q<<endl;
    // cout<<*q<<endl;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // different ways to assign a pointer or initialize a pointer is mentioned above

    int num =5;
    int a = num;
    cout<<"a before "<<num<<endl;
    a++;
    cout<<"a after "<<num<<endl;

    int *p = &num;
    cout<<"before"<<num<<endl;
    (*p)++;
    cout<<"after"<<num<<endl;

    // copying a pointer
    int *q = p;
    cout<<p <<"  --  "<<q<<endl;
    cout<< *p  <<"  --  "<<*q<<endl;

    //important concept
    int i = 3;
    int *t = &i;
    cout<<++(*t)<<endl;
    // *t = *t +1;
    // cout<<*t<<endl;
    cout<<"before t "<<t <<endl;
    t = t+1;
    cout<<"after t "<<t<<endl;
    // integer occupies 4 bytes so t = t+1 increases the value by 4
    // for example if the address stored in t initially was 100 then as i is an integer it occupies space from 100 to 103 and thus t = t+1 updates the address at t to 104
    return 0;


}