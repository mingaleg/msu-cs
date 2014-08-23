#!/usr/bin/bash
# vim: set sw=4 sts=4 et tw=80 :

python gen.py > input.txt
python sol.py < input.txt > answer.txt
./a.out < input.txt > output.txt

diff output.txt answer.txt
