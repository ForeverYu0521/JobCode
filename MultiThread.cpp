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
	printf("第%d次:\n",times);
	times++;
	printf("A\n");
	ReleaseSemaphore(B, 1, NULL);//递增信号量B的资源数

	return 0;
}

unsigned int __stdcall FunB(void *pPM)
{
	Sleep(100);
	printf("B\n");
	ReleaseSemaphore(C, 1, NULL);//递增信号量C的资源数

	return 0;
}

unsigned int __stdcall FunC(void *pPM)
{
	Sleep(100);
	printf("C\n");
	ReleaseSemaphore(A, 1, NULL);//递增信号量A的资源数

	return 0;
}

int main()
{
	//初始化信号量
	A = CreateSemaphore(NULL, 1, 1, NULL);//当前1个资源，最大允许1个同时访问
	B = CreateSemaphore(NULL, 0, 1, NULL);//当前0个资源，最大允许1个同时访问
	C = CreateSemaphore(NULL, 0, 1, NULL);//当前0个资源，最大允许1个同时访问

	HANDLE  handle[Numbers];
	int i = 0;
	while (i < Numbers)
	{
		WaitForSingleObject(A, INFINITE);  //等待信号量A>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunA, &i, 0, NULL);
		WaitForSingleObject(B, INFINITE);  //等待信号量B>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunB, &i, 0, NULL);
		WaitForSingleObject(C, INFINITE);  //等待信号量C>0
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, FunC, &i, 0, NULL);

		++i;
	}
	WaitForMultipleObjects(Numbers, handle, TRUE, INFINITE);

	//销毁信号量
	CloseHandle(A);
	CloseHandle(B);
	CloseHandle(C);
	for (i = 0; i < Numbers; i++)
		CloseHandle(handle[i]);
	return 0;
}
