#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <string>
#include <stack>
#include <windows.h>
#include <process.h>
#include<iostream>

using namespace std;

const int Numbers = 10;
HANDLE            A,B,C;
int times=1;

unsigned int __stdcall FunA(void *pPM)
{
	Sleep(100);//some work should to do
	printf("��%d��:\n",times);
	times++;
	printf("A\n");
	ReleaseSemaphore(B, 1, NULL);//�����ź���B����Դ��

	return 0;
}

unsigned int __stdcall FunB(void *pPM)
{
	Sleep(100);
	printf("B\n");
	ReleaseSemaphore(C, 1, NULL);//�����ź���C����Դ��

	return 0;
}

unsigned int __stdcall FunC(void *pPM)
{
	Sleep(100);
	printf("C\n");
	ReleaseSemaphore(A, 1, NULL);//�����ź���A����Դ��

	return 0;
}

int main()
{
	//��ʼ���ź���
	A = CreateSemaphore(NULL, 1, 1, NULL);//��ǰ1����Դ���������1��ͬʱ����
	B = CreateSemaphore(NULL, 0, 1, NULL);//��ǰ0����Դ���������1��ͬʱ����
	C = CreateSemaphore(NULL, 0, 1, NULL);//��ǰ0����Դ���������1��ͬʱ����

	HANDLE  handle[Numbers];
	int i = 0;
	while (i < Numbers)
	{
		WaitForSingleObject(A, INFINITE);  //�ȴ��ź���A>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunA, &i, 0, NULL);
		WaitForSingleObject(B, INFINITE);  //�ȴ��ź���B>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunB, &i, 0, NULL);
		WaitForSingleObject(C, INFINITE);  //�ȴ��ź���C>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunC, &i, 0, NULL);

		++i;
	}
	WaitForMultipleObjects(Numbers, handle, TRUE, INFINITE);

	//�����ź���
	CloseHandle(A);
	CloseHandle(B);
	CloseHandle(C);
	for (i = 0; i < Numbers; i++)
		CloseHandle(handle[i]);
	return 0;
}
