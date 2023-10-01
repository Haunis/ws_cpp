/*
 *
 *  Created on: Mar 13, 2020
 *      Author: haunis
 */

#ifndef MY_NAME_SPACE_H_2
#define MY_NAME_SPACE_H_2

namespace mySpace
{
    //如果不使用extern，由于mySpace.cpp重新定义了space_name，编译时就会报错"redefinition of ..."
    
    //如果不使用extern，且其他任何地方都没定义space_name，编译时没问题。
    //但如果多个不同cpp文件包含了该头文件就会报链接错误"multiple definition ..."
    extern char *space_name;
    void func2();
} // namespace mySpace

#endif /* MY_NAME_SPACE_H_2 */
