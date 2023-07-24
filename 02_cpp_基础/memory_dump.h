/**
 * @date 2023-07-24
 *  参考：https://zhuanlan.zhihu.com/p/628440593
 * 
 *  使用：
 *      1. 包含该头文件
 *      2. vscode三角形 --> Debug C/C++ File --> 监视窗口填入memory_dump(p,len,$rsp,$rbp)
 *         p   : 要监视的内存起始地址
 *         len : 监视的内存空间大小，单位byte
 *         $rsp: rsp寄存器地址
 *         $rbp: rbp寄存器地址
 * 
 *  debug 指定地址: memory_dump(debug_start_addr, debug_len_byte, $rsp, $rbp)
 * 
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define YELLOW "\033[1;33m"
#define GREEN "\033[0;32;32m"
#define LIGHT_RED "\033[1;31m"
#define LIGHT_GREEN "\033[1;32m"
#define LIGHT_CYAN "\033[1;36m"
#define LIGHT_PURPLE "\033[1;35m"
#define END "\033[m"
#define NONE

#define BYTES_OF_LINE 8    // 设置每行显示字节长度, 若要跟踪某字节推荐值为8
#define MAX_BYTES_LEN 1600 // 设置最大打印字节数

int debug_on = 1;
void *debug_start_addr = (void *)0x7fffffffdb00; // 要查看的内存开始地址
int debug_len_byte = 48;                         // 查看多少内存空间，单位：byte

static int first_debug = 1;
static void *last_debug_start_addr = 0;
static int last_debug_len_bytes = 0;
static unsigned int last_bytes[MAX_BYTES_LEN] = {0};

static void print_short_addr(uint64_t int64_addr, void *rsp_ptr, void *rbp_ptr)
{
    if (int64_addr == (uint64_t)rsp_ptr)
    {
        printf(LIGHT_CYAN "0x%02x:\t" END, (uint16_t)(int64_addr & 0xffff));
    }
    else if (int64_addr == (uint64_t)rbp_ptr)
    {
        printf(LIGHT_PURPLE "0x%02x:\t" END, (uint16_t)(int64_addr & 0xffff));
    }
    else
    {
        printf(LIGHT_GREEN "0x%02x:\t" END, (uint16_t)(int64_addr & 0xffff));
    }
}
/**
 *
 * @param ptr       内存开始地址
 * @param len       容量，单位bytes
 * @param rsp_ptr   rsp寄存器地址
 * @param rbp_ptr   rbp寄存器地址
 */
void memory_dump(void *ptr, int len, void *rsp_ptr, void *rbp_ptr)
{
    if (first_debug)
    {
        printf("set " YELLOW "debug_start_addr, debug_len_byte" END " to dump.\n");
        first_debug = 0;
    }

    // printf("rsp: %p, rbp:%p\n", rsp_ptr, rbp_ptr);

    if (ptr && len && debug_on)
    {
        // 参数与上一次调用是否发生变化
        int is_para_changed = 0;
        if (last_debug_start_addr != debug_start_addr || last_debug_len_bytes != debug_len_byte)
        {
            is_para_changed = 1;
            memset(last_bytes, 0, sizeof(last_bytes)); // 发生变化则将缓冲区清空
        }

        // 打印地址范围
        printf(GREEN "\n%p ~ %p\n" END, ptr, (uint8_t *)ptr + len - 1); // 强转成一字节的的指针

        uint64_t int64_addr = (uint64_t)ptr; // 记录打印的地址，每BYTES_OF_LINE(8)个字节打印一次地址
        for (int i = 0; i < len; i++)
        {
            if (i % BYTES_OF_LINE == 0) // 打印简短地址编号
                print_short_addr(int64_addr, rsp_ptr, rbp_ptr);

            // 内存中取值
            uint8_t this_byte = *((uint8_t *)ptr + i);
            if (!is_para_changed && last_bytes[i] != this_byte)
            {
                printf(LIGHT_RED "%02x " END, this_byte);
            }
            else
            {
                printf("%02x ", this_byte);
            }

            last_bytes[i] = this_byte; // 更新缓存字节

            if ((i + 1) % (BYTES_OF_LINE / 2) == 0) // 每行中间打印一个空格
                printf(" ");
            if ((i + 1) % BYTES_OF_LINE == 0 || i == len - 1) // 换行
            {
                printf("\n");
                int64_addr += (uint64_t)BYTES_OF_LINE;
            }
        }

        last_debug_start_addr = debug_start_addr;
        last_debug_len_bytes = debug_len_byte;
    }
}

/**
 * 不打印地址的简易内存dump
 */
void my_dump(void *ptr, int len)
{
    if (!ptr)
    {
        return;
    }

    for (int i = 0; i < len; i++)
    {
        if (i % 8 == 0 && i != 0)
            printf(" ");
        if (i % 16 == 0 && i != 0)
            printf("\n");
        printf("%02x ", *((uint8_t *)ptr + i));
    }
    printf("\n");
}
