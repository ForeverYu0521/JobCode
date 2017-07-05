#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    float a=1.23456;
    cout<<"直接输出"<<a<<endl;
    cout<<"保留3位有效数字"<<setprecision(3)<<a<<endl;
    cout<<"保留3位小数"<<setiosflags(ios::fixed)<<setprecision(3)<<a<<endl;
    return 0;
}
