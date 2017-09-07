#include<iostream>
#include<string>
#include<assert.h>
#include<stdlib.h>
#include<sstream>

using namespace std;

char* stringcopy(char *strdest,const char *strsrc)
{
    assert((strdest!=NULL&&strsrc!=NULL));
    char* s = strdest;
    while((*strdest++=*strsrc++)!='\0')
        NULL;
    return s;
}
int main()
{
    string s = "qwe,def,dfg";
    string test = "qwe";

    int pos = s.find(test); //�����Ӵ�λ��
    cout<<pos<<endl;

    pos = s.rfind(',');   //�ҵ����һ���ַ�����λ��
    s.insert(pos+1,"insert"); //��ָ��λ�ò����ض����ַ���
    cout<<s<<endl;

    pos = s.rfind(',');
    string s1=s.substr(pos+1); //��ȡ�Ӵ�
    cout<<s1<<endl;

    pos = s.rfind(',');
    s.replace(pos+1,6,"");   //��ָ��λ���滻�ַ���
    cout<<s<<endl;

    pos = s.find_first_of(','); //�ҳ���һ���ַ�����λ��
    s1=s.substr(0,pos);
    cout<<s1<<endl;

    string coms1 = "123";
    string coms2 = "123";
    string coms3 = "12";
    cout<<"�ַ�����ȣ�"<<coms1.compare(coms2)<<endl;
    cout<<"�ַ������ȣ�"<<coms1.compare(coms3)<<endl;

    int comint1 = atoi(coms1.c_str());   //�ַ���ת����
    cout<<comint1<<endl;

    stringstream ss;                    //�ַ���ת����
    ss<<coms1;
    int comint2;
    ss>>comint2;
    cout<<comint2<<endl;

    ss.clear();                       //����ת�ַ���
    ss<<comint1;
    ss>>coms1;
    cout<<coms1<<endl;

    s = "abc,,def,,hi,,j";                //�滻�ַ��������г��ֵ��Ӵ�
    int index = 0;
    string sub = ",,";
    while((pos = s.find(sub,index))!=-1)
    {
        s.replace(pos,sub.size(),".");
        index = pos+1;
    }
    cout<<s<<endl;

    return 0;
}
