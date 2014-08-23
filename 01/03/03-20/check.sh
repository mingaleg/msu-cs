#!/usr/bin/bash
# vim: set sw=4 sts=4 et tw=80 :

n=$1

tst=`echo $n | ./f`
res=`echo $tst | ./a.out`
chk=`echo $res | ./f`

if [[ $chk -ne $tst ]]; then
    echo FAIL: $n $tst $res $chk;
    exit 1
fi
