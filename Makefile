CFLAGS = -Wall -pedantic -ansi

all: menu

menu: menu
	gcc $(CFLAGS) -o menu.o products.o

menu.o: menu.c odbc.h
	gcc $(CFLAGS) -c menu.c
products.o: products.c products.h
	gcc $(CFLAGS) -c products.c
