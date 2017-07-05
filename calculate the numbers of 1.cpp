#include<iostream>

using namespace std;

class Solution
{
public:
    int calculation(int a)
    {
        int counter=0;
        while(a)
        {
            counter++;
            a&=a-1;
        }
        return counter;
    }
};
int main()
{
    Solution *p;
    cout<<p->calculation(0x11530828)<<endl;
    return 0;
}
