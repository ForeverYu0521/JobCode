#include<iostream>
#include<vector>

using namespace std;

int Partition(vector<int> &nums,int start,int end)
{
    int index=start;
    int temp=nums[index];
    for(int i=start+1,j=end;index!=j;)
    {
        if(nums[i]<=temp)
        {
           swap(nums[i],nums[index]);
           index=i;
           i++;
        }
        else
        {
            swap(nums[i],nums[j]);
            j--;
        }
    }
    return index;
}
void QuickSort(vector<int> &nums,int start,int end)
{
    if(start==end)
        return;
    int mid=Partition(nums,start,end);
    if(mid>start)
        QuickSort(nums,start,mid-1);
    if(mid<end)
        QuickSort(nums,mid+1,end);
}
int main()
{
    vector<int> nums={9,5,4,1,7,6,3,2,8};
    QuickSort(nums,0,nums.size()-1);
    for(auto c:nums)
        cout<<c<<endl;
    return 0;
}
