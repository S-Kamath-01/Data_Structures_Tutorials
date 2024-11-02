#include<iostream>
using namespace std;


void update(int **p2){
    // p2 = p2 + 1;
    // NO change
    // *p2 = *p2 + 1; 
    // Changes the valuee stored in p
    **p2 = **p2 + 1;
    // Changes the value stored in i
}
int main(){
    int i = 5;
    int *p = &i;
    int** p2 = &p;

    cout<<endl<<endl<<"Sab sahi chal rha hai"<<endl<<endl;

    cout<<"Printing p "<<p<<endl;
    cout<<"Address of p "<<&p<<endl;

    cout<<*p2<<endl;
    // Three ways to access i 
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;

    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;

    cout<<&p<<endl;
    cout<<p2<<endl;

    cout<<endl<<endl;

    cout<<"before "<<i<<endl;
    cout<<"before "<<p<<endl;
    cout<<"before "<<p2<<endl;

    update(p2);
    cout<<"after "<<i<<endl;
    cout<<"after "<<p<<endl;
    cout<<"after "<<p2<<endl;
    cout<<endl<<endl;



    

    return 0;

}