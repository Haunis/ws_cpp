/**
 * c++ io流：
 * 		https://www.cnblogs.com/kzang/archive/2012/07/16/2593133.html
 * 		https://blog.csdn.net/chenjieyujiayou/article/details/76855763
 * 		https://vimsky.com/examples/usage/fread-function-in-c.html
 *
 * 获取文件大小：
 * 		https://blog.csdn.net/zanda_/article/details/90544856
 *
 * FILE * fopen(const char * path,const char * mode);
 * 	c语言里的函数
 * 	path: 文件路径
 * 	mode: 
 *		“rt”　　　  只读打开一个文本文件,只允许读数据
 *		“wt”　　    只写打开或建立一个文本文件,只允许写数据
 *		“at”　　　  追加打开一个文本文件,并在文件末尾写数据
 *		“rb”	　　只读打开一个二进制文件,只允许读数据
 *		“wb”　　    只写打开或建立一个二进制文件,只允许写数据
 *		“ab”	　　追加打开一个二进制文件,并在文件末尾写数据
 *		“rt+”	　　读写打开一个文本文件,允许读和写
 *		“wt+”	　　读写打开或建立一个文本文件,允许读写
 *		“at+”	　　读写打开一个文本文件,允许读,或在文件末追加数据
 *		“rb+”	　　读写打开一个二进制文件,允许读和写
 *		“wb+”	　　读写打开或建立一个二进制文件,允许读和写
 *		“ab+”	　　读写打开一个二进制文件,允许读,或在文件末追加数据
 *	
 * fread:
 * 		size_t fread(void * buffer, size_t size, size_t count, FILE * stream):
 * 		buffer: 存数据的地方
 *		size: 每个对象的大小，单位是字节
 *		count: 读取对象的数量
 *		stream: 文件指针
 */

#include <iostream>
#include <cstdio>
using namespace std;

const char *file_name = "abc.txt";

size_t getFileSize(const std::string &file_name)
{
	FILE *fp = fopen(file_name.c_str(), "r");
	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fclose(fp);
	return size; // 单位是：byte
}

int main()
{

	FILE *fp;

	fp = fopen(file_name, "r");

	const int fileSize = getFileSize(file_name);
	printf("fileSize=%d\n", fileSize);

	printf("\n---------------1.使用char[]存储---------------------\n");
	char buf[4];
	while (!feof(fp))
	{
		// fread(buf, 1, 4, fp); // 每次读取 1*4个字节
		fread(buf, sizeof(buf), 1, fp); 
		printf("%s\t", buf);
	}

	printf("\n----------------2.使用void*[]存储---------------------\n");
	void *buf2[100];
	fseek(fp, 0, SEEK_SET); // 重新将文件指针指向文件开头
	while (!feof(fp))
	{
		fread(buf2, sizeof(buf2), 1, fp);

		printf("buf2: %s\n", buf2);
	}
	printf("------read end-----\n");
	fclose(fp);

	return 0;
}
