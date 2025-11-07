

.PHONY: basic all clean

basic: ./lib/libmybasic.a
all: ./bin/myapp

./bin/myapp: ./lib/libmybasic.a ./obj/myapp.o
	gcc -o $@ ./obj/myapp.o -lmybasic -L./lib

./lib/libmybasic.a: ./obj/add.o ./obj/div.o ./obj/mul.o ./obj/sub.o
	ar rcs $@ $^

./obj/%.o: ./src/%.c
	gcc -c $< -o $@ -I./include

clean:
	rm -f ./obj/*.o ./bin/myapp ./lib/*.a

