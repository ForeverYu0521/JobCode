#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
    vector<int> a;
    int temp = 0;
    char c;
    cin>>temp;
    a.push_back(temp);
    while((c=getchar())!='\n')
    {
        cin>>temp;
        a.push_back(temp);
    }
    for(auto c:a)
        cout<<c<<endl;
}
