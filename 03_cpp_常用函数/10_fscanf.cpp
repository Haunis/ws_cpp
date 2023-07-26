/**
 * @date 2023-07-26
 *
 *  https://zhuanlan.zhihu.com/p/141506044
 *
 *  fscanf(FILE *stream, char *format, [argument...])
 *      从stream中读取数据按format格式到arg中
 */

#include <stdio.h>
#include <stdlib.h> //exit()

int main()
{
    /*
    abc.txt文件内容：
        10 12 hello
        20 22 world
    */
    const char *fname = "abc.txt";
    int i1, i2;
    char str[10];
    FILE *fp;

    if (!(fp = fopen(fname, "r")))
    {
        printf("Failed to open stat file\n");
        exit(-1);
    }

    fscanf(fp, "%d %d %s", &i1, &i2, str);
    printf("i1=%d, i2=%d, str=%s\n", i1, i1, str);

    fscanf(fp, "%d %d %s", &i1, &i2, str);
    printf("i1=%d, i2=%d, str=%s\n", i1, i1, str);

    fclose(fp);
    return 0;
}