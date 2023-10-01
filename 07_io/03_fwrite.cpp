#include <stdio.h>
#include <stdlib.h>

const char *file_name = "abc.txt";

int main()
{
    printf("\n----------------1. fwrite()---------------------\n");

    FILE *fp = fopen(file_name, "wb+");//读写方式打开二进制文件
    // FILE *fp = fopen(file_name, "ab+"); //读写方式打开，追加写

    const  char *readBuf = "abcdef";
    fwrite(readBuf + 1, 1, 4, fp); // 从readBuf指针处开始读数据，对象大小为1，一次读2个对象，读进fp
    fclose(fp);

    printf("write success...\n");

    printf("\n----------------2. 查看文件---------------------\n");
    fp = fopen(file_name, "r");
	void *buf[100];
	while (!feof(fp))
	{
		fread(buf, 1, 100, fp);

		printf("buf: %s\n", buf);
	}
    fclose(fp);

    return 0;
}