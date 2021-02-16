#! /bin/bash 

RED='\033[31m'
GREEN='\033[32;1m' #1是加粗字体
END='\033[0m'

rm -rf build

cmake . -B build #指定到build目录创建

make -C build # 改变目录到build,再执行make

if [ $? = 0 ];then
	clear
	echo -e "${GREEN} build success ${END}"
	./build/string_demo #执行编译后的文件
else
	echo -e "${RED}编译出现错误${END}"
fi

rm -rf build
