#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int> &arrays,int start,int end)
{
    vector<int> TempArray(end-start+1,0);
    int mid=start+(end-start)/2;
    int temp=0;
    int templeft=start;
    int tempright=mid+1;
    for(;templeft<=mid&&tempright<=end;)
    {
        if(arrays[templeft]>arrays[tempright])
        {
            TempArray[temp++]=arrays[tempright++];
        }
        else
        {
            TempArray[temp++]=arrays[templeft++];
        }
    }
    if(templeft<=mid)
    {
        for(;templeft<=mid;)
            TempArray[temp++]=arrays[templeft++];
    }
    if(tempright<=end)
    {
        for(;tempright<=end;)
            TempArray[temp++]=arrays[tempright++];
    }
    for(auto i=start,j=0;i<=end;i++)
    {
        arrays[i]=TempArray[j++];
    }
}
void MergingSort(vector<int> &arrays,int start,int end)
{
    if(end<=start)
        return;
    int mid=start+(end-start)/2;
    MergingSort(arrays,start,mid);
    MergingSort(arrays,mid+1,end);
    Merge(arrays,start,end);
}
int main(void)
{
    vector<int> arrays={7,4,5,2,6,1,8,3,0,9};
    MergingSort(arrays,0,arrays.size()-1);
    for(auto c:arrays)
        cout<<c<<endl;
    return 0;
}

