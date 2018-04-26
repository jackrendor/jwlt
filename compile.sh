#!/bin/bash
mkdir ./run/ &> /dev/null
echo "[+] Compiling..."
gcc -Wall -Wextra -lm main.c -o ./run/jwlt
