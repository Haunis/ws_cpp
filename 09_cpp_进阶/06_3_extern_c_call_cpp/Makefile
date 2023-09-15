.PHONY : all
all:main.o add.o
	gcc -o main main.o add.o

# 默认cc
main.o:main.c

# 默认g++
add.o:add.h

clean:
	-rm *.o main 
	@echo "clean finished !!!"
	tree
.PHONY : clean
