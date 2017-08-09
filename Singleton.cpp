#include<iostream>

using namespace std;
//�������C++ʵ��
class Singleton
{
    private:
     Singleton();//ע��:���췽��˽��
     virtual ~Singleton();
     static Singleton* instance;//Ωһʵ��
     int var;//��Ա����(���ڲ���)
    public:
     static Singleton* GetInstance();//��������(�������ʵ��)
     int getVar();//���var��ֵ
     void setVar(int);//����var��ֵ
};
//���췽��ʵ��
Singleton::Singleton()
{
 this->var = 20;
 cout<<"Singleton Constructor"<<endl;
}
/*
Singleton::~Singleton()
{
    delete instance;
}
*/
Singleton::~Singleton()
{
 if(instance != NULL)
 {
  delete instance;
 }
}
//��ʼ����̬��Ա
//Singleton* Singleton::instance=new Singleton();
Singleton* Singleton::instance=NULL;
Singleton* Singleton::GetInstance()
{
 if(instance == NULL)
 {
  instance = new Singleton();
 }
 return instance;
}
//seter && getter����
int Singleton::getVar()
{
 return this->var;
}
void Singleton::setVar(int var)
{
 this->var = var;
}
//main
int main(int argc, char* argv[])
{
 Singleton *ton1 = Singleton::GetInstance();
 Singleton *ton2 = Singleton::GetInstance();
 cout<<"ton1 var = "<<ton1->getVar()<<endl;
 ton1->setVar(150);
 cout<<"ton2 var = "<<ton2->getVar()<<endl;
 return 0;
}
