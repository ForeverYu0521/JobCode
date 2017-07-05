#include<iostream>
#define AveAge 21;

using namespace std;

int main()
{
    int W=168,Y=26,N=78;
    float x=0.4;
    int Numbers=W*(1-x);
    for(int i=0;i<N-1;i++)
	{
        int TotalAge=Numbers*Y+(W-Numbers)*AveAge;
        float ave=TotalAge/W;
        Y=(int)TotalAge/W;
        int j=10*ave-10*Y;
        if(j>=5)
            Y=Y+1;
    }
    cout<<Y;
    return 0;
}
