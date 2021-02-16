.PHONY : all
all:main.o add.o
	gcc -o main main.o add.o

main.o:main.c

add.o:add.h

clean:
	-rm *.o main 
	@echo "clean finished !!!"
	tree
.PHONY : clean
