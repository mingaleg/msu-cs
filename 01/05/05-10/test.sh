#!/usr/bin/bash
# vim: set sw=4 sts=4 et tw=80 :

./gen.py > input.txt
./true.py < input.txt > answer.txt
./petr < input.txt > output.txt

diff -w output.txt answer.txt
