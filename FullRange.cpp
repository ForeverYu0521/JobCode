#include<iostream>
#include<vector>

using namespace std;

template<class T>
bool IsSwap(vector<T> &a, int k,int m)
{
    for(int i=k;i<m;i++)
    {
        if(a[i]==a[m])
            return false;
    }
    return true;
}

template<class T>
void AllRangeOfRecursion(vector<T> &a, int k, int m)
{
    if (k == m)
    {
        static int s_i = 1;
        cout<< "µÚ " << s_i++ << "¸öÅÅÁÐ:" ;
        for(auto c: a)
            cout<< c << " ";
        cout<<endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            if(IsSwap(a,k,i))
            {
                swap(a[k], a[i]);
                AllRangeOfRecursion(a, k + 1, m);
                swap(a[k], a[i]);
            }
        }
    }
}
int main()
{
    vector<char> a = {'a','b','c'};
    vector<int> b = {1,2,2};
    AllRangeOfRecursion(a,0,a.size()-1);
    AllRangeOfRecursion(b,0,b.size()-1);
    return 0;
}
