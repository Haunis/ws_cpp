/**
 *  可以用来获取文件大小
 *      https://blog.csdn.net/weixin_41169280/article/details/109862430
 * 
 *  int fseek(FILE *stream, long int offset, int whence):
 *     stream: 为文件指针
 *     offset:偏移量 ，正数表示正向偏移，负数表示负向偏移
 *     whence:设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET
 *  　　    SEEK_SET： 文件开头
 *  　　    SEEK_CUR： 当前位置
 *  　　    SEEK_END： 文件结尾
 *     返回值：当调用成功时则返回0，若有错误则返回-1，errno会存放错误代码。
 */

#include <stdio.h>

const char *FILE_RD = "abc.txt";

int main(int arc, char *argv[])
{
    long pos;
    FILE *fp = fopen(FILE_RD, "r");


    fseek(fp, 0, SEEK_END);
    pos = ftell(fp);
    printf("pos = %ld\n", pos);

    fclose(fp);
    return 0;
}