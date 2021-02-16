//============================================================================
// Name        : cpp_fread.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	FILE *file_;
	void *buffer[100];
	file_ = fopen("abc.txt", "r"); //在eclipse中,abc.txt要放到工程的根目录里
	while (!feof(file_)) // to read file
	{
		// fucntion used to read the contents of file
		fread(buffer, sizeof(buffer), 1, file_);
		// cout << buffer;
	}

	cout << (char*) buffer << endl;
	return 0;
}
