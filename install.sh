#!/bin/bash

if [ -f ./run/jwlt ]; then
	cp ./run/jwlt /usr/sbin/jwlt
	if [ $? -eq 0 ]; then
		echo "[+] Installed"
	else
		echo "[ERROR] Need to be root?"
	fi
else
	echo "[ERROR] You need first compile"
fi

