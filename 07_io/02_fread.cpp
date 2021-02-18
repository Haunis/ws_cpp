/**
 * c++ io流：
 * 		https://www.cnblogs.com/kzang/archive/2012/07/16/2593133.html
 * 		https://blog.csdn.net/chenjieyujiayou/article/details/76855763
 * 		https://vimsky.com/examples/usage/fread-function-in-c.html
 * 
 * 获取文件大小：
 * 		https://blog.csdn.net/zanda_/article/details/90544856
 * 
 * fopen是c语言里的函数
 * 
 * fread:
 * 		size_t fread(void * buffer, size_t size, size_t count, FILE * stream):
 * 		buffer:它以至少(size * count)个字节的大小指定指向内存块的指针以存储对象。
 *		size:要读的字节数
 *		count:它指定元素的数量，每个元素的大小为字节大小。
 *		stream:文件指针
 */

#include <iostream>
#include <cstdio>
using namespace std;

size_t getFileSize(const std::string &file_name)
{
	FILE *fp = fopen(file_name.c_str(), "r");
	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fclose(fp);
	return size; //单位是：byte
}
const char *FILE_RD = "abc.txt";

int main()
{

	FILE *fp;

	fp = fopen(FILE_RD, "r");

	printf("------------------1.使用char[]存储---------------------\n");
	int fileSize = getFileSize(FILE_RD);

	char buffer[fileSize];
	printf("fileSize=%d, sizeof(buffer)=%lu\n", fileSize, sizeof(buffer));

	fread(buffer, sizeof(buffer), 1, fp);

	printf("buffer: %s\n", buffer);
	for (int i = 0; i < fileSize; i++)
	{
		printf("%c\t", buffer[i]);
	}
	printf("\n");

	printf("\n------------------2.使用void*[]存储---------------------\n");

	void *buffer2[100];
	fseek(fp, 0, SEEK_SET);
	while (!feof(fp))
	{
		fread(buffer2, sizeof(buffer2), 1, fp);

		printf("buffer2: %s\n", buffer2);
	}
	printf("------read end-----\n");

	return 0;
}
