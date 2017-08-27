#include<iostream>

using namespace std;

/************************************
����x^n
������2^23��
���д��2^16 * 2^4 * 2^2 * 2
��23ת���ɶ�����Ϊ10111��ʹ�������
�㷨���Լ����ظ�������
************************************/
int power(int x, unsigned int n)
{
    if(n == 0)
        return 1;
    int result = 1;
    while(0!=n)
    {
        if(0 != (n&1))
        {
            result = result * x;
        }
        x *= x;
        n >>= 1;
    }
    return result;
}

int main()
{
    cout<< power(-2,9) <<endl;
    return 0;
}
