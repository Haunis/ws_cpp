/**
 *  一、判断文件是否存在
 *      https://blog.csdn.net/yohnyang/article/details/131342539
 *      1.C语言：access
 *          头文件： <unistd.h>
 *          int access(const char *filename, int mode);
 *              返回0则表示存在，-1表示不存在
 *              mode	Description
 *              F_OK	测试文件是否存在
 *              R_OK	测试文件是否有读权限
 *              W_OK	测试文件是否有写权限
 *              X_OK	测试文件是否有执行权限
 *      2.C++: ifstream
 *          头文件: <fstream> 并且使用 using namespace std;
 *          ifstream.good(); //返回bool
 *      3.fopen()
 *
 *      4.stat()
 *          头文件： <sys/stat.h>
 *          struct stat buffer;
 *          int ret = stat(name.c_str(), &buffer); //返回0则表示存在
 *
 * 二、删除文件
 *      https://blog.csdn.net/YT21198/article/details/131115345
 *      remove()
 *
 */

#include <stdio.h>
#include <unistd.h> //access()
#include <fstream>
#include <sys/stat.h>
#include <string.h> //strlen

using namespace std;

void creat_file(const char* f_name){
    FILE *fp = fopen(f_name, "ab+"); // 追加写
    const char *msg = "12345678";
    fwrite(msg, strlen(msg), 1, fp);
    fclose(fp);
}
int main()
{
    const char *f_name = "abc.txt";

    printf("\n-----------------1.1 文件是否存在: access------------------\n");
    int ret = access(f_name, F_OK);
    printf("%s  %s\n", f_name, ret == 0 ? "存在" : "不存在");

    printf("\n-----------------1.2 文件是否存在: ifstream------------------\n");
    ifstream f(f_name);
    printf("%s  %s\n", f_name, f.good() ? "存在" : "不存在");

    printf("\n-----------------1.3 文件是否存在: fopen------------------\n");
    FILE *file = fopen(f_name, "r");
    printf("%s  %s\n", f_name, file != nullptr ? "存在" : "不存在");

    if (file != nullptr)
    {
        fclose(file);
    }

    printf("\n-----------------1.4 文件是否存在: stat------------------\n");
    struct stat buffer;
    ret = stat(f_name, &buffer);
    printf("%s  %s\n", f_name, ret == 0 ? "存在" : "不存在");

    printf("\n-----------------2. 删除文件------------------\n");
    const char *f_name2 = "aaa.txt";
    creat_file(f_name2);

    ret = remove(f_name2);
    printf("删除 %s  %s\n", f_name2, ret == 0 ? "成功" : "失败");

    return 0;
}