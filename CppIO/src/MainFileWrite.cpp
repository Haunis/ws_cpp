/*
 * MainFileWrite.cpp
 *
 *  Created on: 2019年3月12日
 *      Author: BTI-PC
 *
 *	C++标准函数之打开文件
 *	1.主要涉及的类
 *		ofstream	写操作文件类		--由ostream引申而来
 *		ifstream	读操作文件类		--由istream引申而来
 *		fstream		可同时读写操作的文件类	--由iostream引申而来
 *	2.API使用
 *		a.	ofstream file;
 *		b.	file.open("example.bin",ios::out|ios::app|ios::binary);
 *
 *		第二个参数说明：
 *		ios::in			为输入（读）而打开文件
 *		ios::out		为输出（写）而打开文件
 *		ios::ate		初始位置：文件尾
 *		ios::app		所有输出附加在文件末尾
 *		ios::trunc		如果文件已存在，则先删除该文件
 *		ios::binary		二进制文件
 *
 *		不同类默认不同打开方式
 *		ofstream	ios::out|ios::trunc
 *		ifstream	ios::in
 *		fstream		ios::in|ios::out
 *
 *	3.获得和设置流指针
 *		tellg();	返回get流指针的位置，是个整数
 *		tellp();	返回put流指针的位置，是个整数
 *
 *		seekg(pos_type position);	改变get流指针的位置，指针放置在从文件开始的位置偏移position个位置
 *		seekp(pos_type position);	改变put流指针的位置，指针放置在从文件开始的位置偏移position个位置
 *
 *		seekg(off_type offset,seekdir direction);	改变get流指针的位置，指针放置在以direction方向开始偏移offset个位置
 *		seekp(off_type offset,seekdir direction);	改变put流指针的位置，指针放置在以direction方向开始偏移offset个位置
 *
 *		seekdir:	1.ios::beg	2.ios::cur	3.ios::end
 */

#include<iostream>
#include<fstream>
using namespace std;

string fileToWrite = "example.txt";
string fileToRead = fileToWrite;
void writeFile(string);
void readFile(string);
void getFileSize(string);
void read(string);
int main() {
	cout<<"writeFile--------------------------"<<endl;
	writeFile(fileToWrite);

	cout<<"readFile--------------------------"<<endl;
	readFile(fileToRead);

	cout<<"getFileSize--------------------------"<<endl;
	getFileSize(fileToRead);

	cout<<"read--------------------------"<<endl;
	read(fileToRead);
	return 0;
}
void read(string fileName) {
	char* buffer;
	long size;
	ifstream exampleFile(fileName, ios::in | ios::binary | ios::ate); //初始位置:文件末尾
	size = exampleFile.tellg();
	exampleFile.seekg(0, ios::beg);
	buffer = new char[size];
	cout << "before buffer : " << buffer << endl;
	exampleFile.read(buffer, size);
	exampleFile.close();

	cout << "after buffer : " << buffer << endl;

	delete[] buffer;
}
void getFileSize(string fileName) {
	long beginPos, endPos;
	ifstream exampleFile(fileName);
	beginPos = exampleFile.tellg(); //返回当前get流指针的位置
	exampleFile.seekg(0, ios::end); //从end开始向后偏移0个位移后，再返回指针位置
	endPos = exampleFile.tellg();
	exampleFile.close();

	cout << "beginPos = " << beginPos << endl;
	cout << fileName + " size : " << endPos - beginPos << " bytes" << endl;

}
void readFile(string fileName) {
	char buffer[256];
	ifstream exampleFile(fileName);
	if (!exampleFile.is_open()) {
		cout << "Error Opening File";
		exit(0);
	}
	while (!exampleFile.eof()) {
		exampleFile.getline(buffer, 100);//第二个参数是读取的最大字符数
		cout << buffer << endl;
	}

}
void writeFile(string fileName) {
	//无此文件则创建；文件位置：工程根目录下，运行完refresh工程
	ofstream exampleFile(fileName);
	if (exampleFile.is_open()) {
		exampleFile << "this is a line.\n";
		exampleFile << "this is another line.\n";
		exampleFile.close();
	} else {
		cout << "not open" << endl;
	}
}

