#!/usr/bin/bash
# vim: set sw=4 sts=4 et tw=80 :

python gen.py 500 > input.txt
./a.out < input.txt > output.txt
python check.py

