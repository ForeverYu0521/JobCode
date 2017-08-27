#include<iostream>

using namespace std;

/************************************
计算x^n
假设求2^23；
则可写成2^16 * 2^4 * 2^2 * 2
而23转换成二进制为10111，使用下面的
算法可以减少重复计算量
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
