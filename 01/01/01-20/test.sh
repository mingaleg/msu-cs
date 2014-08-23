#!/usr/bin/bash
# vim: set sw=4 sts=4 et tw=80 :

while [[ true ]]; do

python gen.py > input
./ac < input > answer
./a.out < input > output
diff answer output

if [[ $? -ne 0 ]]; then
    echo "FAIL";
    beep;
    break;
fi

done
