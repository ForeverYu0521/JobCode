#include<iostream>
#include<string>
#include<assert.h>
#include<stdlib.h>
#include<sstream>
#include<string.h>
#include<stdio.h>

using namespace std;

/***************************************************
编写string类的构造方法，析构函数和赋值函数
***************************************************/
class NewString
{
public:
    NewString(const char *str = NULL);  //普通构造函数
    NewString(const NewString &other);      //拷贝构造函数
    ~NewString(void);                  //析构函数
    NewString & operator =(const NewString &other);
private:
    char *m_data;
};
//普通构造函数
NewString::NewString(const char *str)
{
    if(str == NULL)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length+1];
        strcpy(m_data,str);
    }
}
//拷贝构造函数
NewString::NewString(const NewString &other)
{
    int length = strlen(other.m_data);
    m_data = new char[length+1];
    strcpy(m_data, other.m_data);
}
//析构函数
NewString::~NewString(void)
{
    delete[] m_data;
}



//赋值函数
NewString & NewString::operator=(const NewString &other)
{
    if(this == &other)    //检查自赋值,this是指针，故比较对象为&other
        return *this;
    delete[] m_data;    //释放原有的内存资源
    int length = strlen(other.m_data);
    m_data = new char[length+1];
    strcpy(m_data, other.m_data);
    return *this;
}
//NewString类的测试函数
void TestNewString(void)
{
    NewString S1 = "abcdefg";
    NewString S2(S1);
    NewString *S3 =new NewString(S2);
}

char* stringcopy(char *strdest, const char *strsrc)
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

    int pos = s.find(test); //查找子串位置
    cout<<pos<<endl;

    pos = s.rfind(',');   //找到最后一个字符所在位置
    s.insert(pos+1,"insert"); //在指定位置插入特定的字符串
    cout<<s<<endl;

    pos = s.rfind(',');
    string s1=s.substr(pos+1); //提取子串
    cout<<s1<<endl;

    pos = s.rfind(',');
    s.replace(pos+1,6,"");   //在指定位置替换字符串
    cout<<s<<endl;

    pos = s.find_first_of(','); //找出第一个字符所在位置
    s1=s.substr(0,pos);
    cout<<s1<<endl;

    string coms1 = "123";
    string coms2 = "123";
    string coms3 = "12";
    cout<<"字符串相等："<<coms1.compare(coms2)<<endl;
    cout<<"字符串不等："<<coms1.compare(coms3)<<endl;

    int comint1 = atoi(coms1.c_str());   //字符串转整型
    cout<<comint1<<endl;

    stringstream ss;                    //字符串转整型
    ss<<coms1;
    int comint2;
    ss>>comint2;
    cout<<comint2<<endl;

    ss.clear();                       //整型转字符串
    ss<<comint1;
    ss>>coms1;
    cout<<coms1<<endl;

    s = "abc,,def,,hi,,j";                //替换字符串中所有出现的子串
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
