.PHONY : all
all:main.o add.o
	g++ -o main main.o add.o

# 默认使用g++
main.o:main.cpp

# 默认使用cc
# add.o:add.h//ok
add.o:add.c

clean:
	-rm *.o main 
	@echo "clean finished !!!"
	tree
.PHONY : clean
