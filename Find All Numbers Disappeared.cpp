#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<int> FindDisappearNumber(vector<int> &nums)
{
    for(int i=0;i<nums.size();i++)
    {
        int number=abs(nums[i])-1;
        nums[number]=nums[number]>0?-nums[number]:nums[number];
    }
    vector<int> results;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>0)
            results.push_back(i++);
    }
    return results;
}
int main()
{
    return 0;
}
