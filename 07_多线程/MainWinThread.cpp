/*
 * MainWinThread.cpp
 *
 *  Created on: 2019年3月14日
 *      Author: BTI-PC
 */

#include<iostream>
#include <windows.h>
using namespace std;

DWORD WINAPI ThreadProc(LPVOID lpParameter) {
	for (int i = 0; i < 5; ++i) {
		cout << "子线程:i = " << i << endl;
		Sleep(100);
	}
	return 0L;
}

int main() {
	cout << "windows thread" << endl;

//	windows 下创建多线程
	//创建一个线程
	HANDLE thread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
	//关闭线程
	CloseHandle(thread);

	//主线程的执行路径
	for (int i = 0; i < 5; ++i) {
		cout << "主线程:i = " << i << endl;
		Sleep(100);
	}
	return 0;
}

