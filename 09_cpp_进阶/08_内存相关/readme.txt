c++/内存模型：

linux系统中，程序在内存的分布如下：

 ————————————————————————————————————————————————————————————————————————————————————————————————————————
|   低地址   |   .text   |   .data   |   .bss   |   堆-->   |   unused   |   <--栈   |   env   |   高地址   |
 ————————————————————————————————————————————————————————————————————————————————————————————————————————


 ———————————
|   低地址   | 
|   .text   | 
|   .data   |
|   .bss    |
|   heap    |
|     ￬     |
|   unused  |
|     ￪     |
|   stack   | 
|   env     |
|   高地址   |
 ———————————

 ———————————
|   低地址   | 
 ———————————
|   .text   | 
 ———————————
|   .data   |
 ———————————
|   .bss    |
 ———————————
|   heap    |
|     ￬     |
 ———————————
|   unused  |
 ———————————
|     ￪     |
|   stack   | 
 ———————————
|   env     |
 ———————————
|   高地址   |
 ———————————

    .text   程序编译后的主体，即程序的机器指令
    .data   初始化的全局变量
    .bss    声明但未初始化的全局变量
    heap    动态内存，如malloc、new申请的内存; 向高地址方向增长
    stack   用来进行函数调用，保存函数参数，临时变量，返回地址等


