#!/usr/bin/python
import subprocess
for num in range(0,18):
    f = pow(2, num)
    print "Quantity of elements in array: " + str(f)
    out = subprocess.check_output(["./sort", "1", str(f)])
    lst = out.splitlines(True)
    s = lst[len(lst)-1]
    print "Spended for sort " + s[0: len(s)-2] + " ms"
    print "------------------------------------------"
