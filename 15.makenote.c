

#cleam:
#	rm -rf $(obj) a.out
#.PHONY:clean ALL


#main.o:main.c
#	gcc -c main.c -o main.o
#dis.o:dis.c
#	gcc -c dis.c -o dis.o
#add.o:add.c
#	gcc -c add.c -o add.o
#a.out:$(obj)
#	gcc $(obj) -o a.out
#$@表示规则中的目标
#$<表示所有依赖条件
#$^表示第一个以来条件
#替换为以下
#src=$(wildcard ./*.c)  #main.c add.c dis.c
#obj=$(patsubst %c,%o,$(src) )#main.o dis.o add.o

#a.out:$(obj)
#	gcc $^ -o $@
#main.o:main.c
#	gcc -c $< -o $@
#dis.o:dis.c
#	gcc -c $< -o $@
#add.o:add.c
#	gcc -c $< -o $@
#clean:
