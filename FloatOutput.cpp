#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    float a=1.23456;
    cout<<"ֱ�����"<<a<<endl;
    cout<<"����3λ��Ч����"<<setprecision(3)<<a<<endl;
    cout<<"����3λС��"<<setiosflags(ios::fixed)<<setprecision(3)<<a<<endl;
    return 0;
}
