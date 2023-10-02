#include <stdio.h>
#include <stdlib.h>


// 分离立体声pcm数据
// https://blog.csdn.net/weixin_51178981/article/details/117908582
 

int pcm16_split(char *fileName)
{
	FILE *fp = fopen(fileName, "rb+");
	FILE *fp1 = fopen("left.pcm", "wb+");
	FILE *fp2 = fopen("right.pcm", "wb+");
	// malloc = 4S是因为左声道和右声道的采样值是间隔存储的。每个采样值占用2Byte空间，一共4个字节。
	unsigned char *readBuf = (unsigned char *)malloc(4);
	// feof(p)用于判断文件指针p在其所指的文件中的位置，如果到文件末，函数返回1，否则返回0
	while (!feof(fp))
	{
		fread(readBuf, 1, 4, fp);
		//左声道
		fwrite(readBuf, 1, 2, fp1);
		//右声道
		fwrite(readBuf + 2, 1, 2, fp2);
	}
	free(readBuf);
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	return 0;
}

int main()
{
	pcm16_split("recorddemo/tmp.pcm");
	return 0;
}
