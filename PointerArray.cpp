#include<iostream>

using namespace std;

int main()
{
    int a[3][3]={11,12,13,21,22,23,31,32,33};
    int (*p)[3];
    p=a;
    cout<<*p<<endl;
    cout<<*p[0]<<endl;
    cout<<*p+1<<" "<<*(p+1)<<endl;
    cout<<**p+1<<" "<<**(p+1)<<endl;
    cout<<*(p[0]+1)<<endl;
    cout<<(*p)[2]<<" "<<*p[2]<<endl;
    return 0;
}
