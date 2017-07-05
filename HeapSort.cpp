#include <iostream>
#include <vector>

using namespace std;
/*************************************************************
由于树的节点从1开始，而数组从0开始，因此凡遇到与arrays[]有关，
都是代表下标+1 个节点，如arrays[j-1]代表二叉树中第j个节点
*************************************************************/

void HeapBuildFromArray(vector<int> &arrays)            //这个函数可以和下面的函数写成一个，为了便于理解，特意写成两个函数
{
    int length=arrays.size();
    for(int j=length/2;j>0;j--)                         //先从最后一个非叶子节点开始构造，这样在进行其他非叶子节点的调整时，除该节点外，其
    {                                                   //他均符合顶堆的定义
        int temp;
        temp=arrays[j-1];
        int nums=j;
        for(int i=2*nums;i<=length;i=2*i)               //以第j个节点为根节点，构造顶堆，直到结构符合顶堆性质，结束调整
        {                                               //对于完全二叉树而言，节点*2就代表此节点的左孩子节点
            if(i<length&&arrays[i-1]<arrays[i])         //当右孩子节点比左孩子节点的值大时，便将i变更为右孩子节点
            {
                i++;
            }
            if(temp>=arrays[i-1])                      //说明不需要再进行调整，此时以节点j为根节点的二叉树调整完毕
                break;
            arrays[nums-1]=arrays[i-1];
            nums=i;
        }
        arrays[nums-1]=temp;
    }
}
void HeapBuild(vector<int> &arrays,int length)
{
    int temp;
    temp=arrays[0];
    int nums=1;
    for(int i=2*nums;i<=length;i=2*i)          //进行堆的构造时，只需对左右子树的其中一边进行调整，与上面的第二层循环代码相同
    {
        if(i<length&&arrays[i-1]<arrays[i])
        {
            i++;
        }
        if(temp>=arrays[i-1])
            break;
        arrays[nums-1]=arrays[i-1];
        nums=i;
    }
    arrays[nums-1]=temp;
}
void HeapSort(vector<int> &arrays)
{
    HeapBuildFromArray(arrays);
    int length=arrays.size();
    for(int i=length;i>1;i--)
    {
        swap(arrays[0],arrays[i-1]);
        HeapBuild(arrays,i-2);
    }
}
int main()
{
    vector<int> arrays={4,8,2,3,7,5,9,1,6,3,6,10,-1};
    HeapSort(arrays);
    for(auto c:arrays)
        cout<<c<<endl;
    return 0;
}
