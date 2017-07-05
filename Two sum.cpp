#include<iostream>
#include<map>
#include<vector>

using namespace std;
vector<int> twosum(vector<int> &numbers,int target)
{
    vector<int> results;
    map<int,int> Hash;
    for(int i=0;i<numbers.size();i++)
    {
       int NumberToFind=target-numbers[i];
       if(Hash.find(NumberToFind)!=Hash.end())
       {
           results.push_back(Hash[NumberToFind]);
           results.push_back(i);
       }
       Hash[numbers[i]]=i;
    }
    return results;
}
int main()
{
    vector<int> S={3,2,4};
    vector<int> T=twosum(S,6);
    for(auto it:T)
        cout<<it<<endl;
    return 0;
}
