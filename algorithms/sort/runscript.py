#!/usr/bin/python
import subprocess

#Elementary sort
print "Bubble:"
for num in range(5,16):
    f = pow(2, num)
    print "Quantity of elements in array: " + str(f)
    out = subprocess.check_output(["./bubble/sort", "1", str(f)])
    lst = out.splitlines(True)
    s = lst[len(lst)-1]
    print "Spended for sort " + s[0: len(s)-2] + " ms"
    print "------------------------------------------"

print "Comparison estimation:"
for num in range(5,16):
    f = pow(2, num)
    print "Quantity of elements in array: " + str(f)
    out = subprocess.check_output(["./comparisonestimation/sort", "1", str(f)])
    lst = out.splitlines(True)
    s = lst[len(lst)-1]
    print "Spended for sort " + s[0: len(s)-2] + " ms"
    print "------------------------------------------"

print "Shell:"
for num in range(5,17):
    f = pow(2, num)
    print "Quantity of elements in array: " + str(f)
    out = subprocess.check_output(["./shell/sort", "1", str(f)])
    lst = out.splitlines(True)
    s = lst[len(lst)-1]
    print "Spended for sort " + s[0: len(s)-2] + " ms"
    print "------------------------------------------"  

#Advanced
print "Merge sort, base variant:"
for num in range(5,22):
    f = pow(2, num)
    print "Quantity of elements in array: " + str(f)
    out = subprocess.check_output(["./mergebase/sort", "1", str(f)])
    lst = out.splitlines(True)
    s = lst[len(lst)-1]
    print "Spended for sort " + s[0: len(s)-2] + " ms"
    print "------------------------------------------"

print "Binary queue:"
for num in range(5,22):
    f = pow(2, num)
    print "Quantity of elements in array: " + str(f)
    out = subprocess.check_output(["./binqsort/sort", "1", str(f)])
    lst = out.splitlines(True)
    s = lst[len(lst)-1]
    print "Spended for sort " + s[0: len(s)-2] + " ms"
    print "------------------------------------------"

print "Prior queue:"
for num in range(5,22):
    f = pow(2, num)
    print "Quantity of elements in array: " + str(f)
    out = subprocess.check_output(["./pqsort/sort", "1", str(f)])
    lst = out.splitlines(True)
    s = lst[len(lst)-1]
    print "Spended for sort " + s[0: len(s)-2] + " ms"
    print "------------------------------------------"
