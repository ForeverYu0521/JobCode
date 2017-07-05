#include <iostream>
#include <vector>

using namespace std;
/*************************************************************
�������Ľڵ��1��ʼ���������0��ʼ����˷�������arrays[]�йأ�
���Ǵ����±�+1 ���ڵ㣬��arrays[j-1]����������е�j���ڵ�
*************************************************************/

void HeapBuildFromArray(vector<int> &arrays)            //����������Ժ�����ĺ���д��һ����Ϊ�˱�����⣬����д����������
{
    int length=arrays.size();
    for(int j=length/2;j>0;j--)                         //�ȴ����һ����Ҷ�ӽڵ㿪ʼ���죬�����ڽ���������Ҷ�ӽڵ�ĵ���ʱ�����ýڵ��⣬��
    {                                                   //�������϶��ѵĶ���
        int temp;
        temp=arrays[j-1];
        int nums=j;
        for(int i=2*nums;i<=length;i=2*i)               //�Ե�j���ڵ�Ϊ���ڵ㣬���춥�ѣ�ֱ���ṹ���϶������ʣ���������
        {                                               //������ȫ���������ԣ��ڵ�*2�ʹ���˽ڵ�����ӽڵ�
            if(i<length&&arrays[i-1]<arrays[i])         //���Һ��ӽڵ�����ӽڵ��ֵ��ʱ���㽫i���Ϊ�Һ��ӽڵ�
            {
                i++;
            }
            if(temp>=arrays[i-1])                      //˵������Ҫ�ٽ��е�������ʱ�Խڵ�jΪ���ڵ�Ķ������������
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
    for(int i=2*nums;i<=length;i=2*i)          //���жѵĹ���ʱ��ֻ�����������������һ�߽��е�����������ĵڶ���ѭ��������ͬ
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
