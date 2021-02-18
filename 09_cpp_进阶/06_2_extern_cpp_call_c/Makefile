.PHONY : all
all:main.o add.o
	g++ -o main main.o add.o

main.o:main.cpp

# add.o:add.h//ok
add.o:add.c

clean:
	-rm *.o main 
	@echo "clean finished !!!"
	tree
.PHONY : clean
