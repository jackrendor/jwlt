#!/bin/bash
mkdir ./run/ &> /dev/null
echo "[+] Compiling..."
g++ -Wall -Wextra -lm main.cpp -o ./run/jwlt
