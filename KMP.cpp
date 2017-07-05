#include<iostream>

using namespace std;
void getnext(string T,int *next)
{
    int j=0;
    int k=-1;
    next[0]=-1;
    while(T[j]!='\0')
    {
        if(k==-1||T[j]==T[k])
        {
            ++j;
            ++k;
            if(T[j]!=T[k])
                next[j]=k;
            else
                next[j]=next[k];
        }
        else
            k=next[k];
    }

}
int main()
{
    string s="abcac";
    int a[5];
    getnext(s,a);
    for(int i=0;i<5;i++)
        cout<<a[i]<<endl;
    return 0;
}
