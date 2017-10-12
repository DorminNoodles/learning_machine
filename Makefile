




all :
	make -C libft/
	clang -lncurses main.c -I libft/includes libft/libft.a

clean :
	rm -f main.o

re : clean all
