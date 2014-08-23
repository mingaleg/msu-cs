#!/usr/bin/bash
# vim: set sw=4 sts=4 et tw=80 :

i=1
while [ true ]; do
echo $i
i=`expr $i + 1`
python gen.py > input.txt;
./sol < input.txt > output.txt;
python true.py < input.txt > answer.txt;

diff output.txt answer.txt;
if [ $? -gt 0 ]; then echo FAIL; break; fi;
done
