#!/bin/sh
echo "$1"
gcc -c main.c -I inc -o obj/main.o
gcc -c get_next_line.c -o obj/get_next_line.o
gcc -c get_next_line_utils.c -o obj/get_next_line_utils.o
gcc obj/main.o obj/get_next_line.o obj/get_next_line_utils.o $1 -D BUFFER_SIZE=1 -o test_buf1
gcc obj/main.o obj/get_next_line.o obj/get_next_line_utils.o $1 -D BUFFER_SIZE=16 -o test_buf16
gcc obj/main.o obj/get_next_line.o obj/get_next_line_utils.o $1 -D BUFFER_SIZE=32 -o test_buf32
gcc obj/main.o obj/get_next_line.o obj/get_next_line_utils.o $1 -D BUFFER_SIZE=80 -o test_buf80
gcc obj/main.o obj/get_next_line.o obj/get_next_line_utils.o $1 -D BUFFER_SIZE=200 -o test_buf200
gcc obj/main.o obj/get_next_line.o obj/get_next_line_utils.o $1 -D BUFFER_SIZE=1000 -o test_buf1000
gcc obj/main.o obj/get_next_line.o obj/get_next_line_utils.o $1 -D BUFFER_SIZE=9999 -o test_buf9999
