#ifndef DATA_H_
#define DATA_H_

/////////////////////09_枚举使用//////////////////////
enum Color
{
	red, green, blue, white=100, black
} myColor; //myColor是枚举变量

typedef enum Config //类型名Config可以不要
{

	CONFIG_1 = 100, CONFIG_2 = 200,

} My_Config; //别名My_Config可以不要

#endif /* DATA_H_ */
