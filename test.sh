#!/bin/sh

clear
printf '\x1B[37mBUF_SIZE 1:'
./test_buf1
printf '\x1B[37m\nBUF SIZE 16:'
./test_buf16
printf '\x1B[37m\nBUF SIZE 32:'
./test_buf32
printf '\x1B[37m\nBUF SIZE 80:'
./test_buf80
printf '\x1B[37m\nBUF SIZE 200:'
./test_buf200
printf '\x1B[37m\nBUF SIZE 1000:'
./test_buf1000
printf '\x1B[37m\nBUF SIZE 9999:'
./test_buf9999
echo '\x1B[37m\nTEST OVER'
