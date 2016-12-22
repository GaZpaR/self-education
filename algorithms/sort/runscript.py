#!/usr/bin/python
import subprocess

def runBenchmark(power, sortName):
    print "------------------------------------------"
    print "| Sort type: " + sortName + " |"
    print "------------------------------------------"
    for num in range(5,power):
        f = pow(2, num)
        print "Quantity of elements in array: " + str(f)
        out = subprocess.check_output(["./" + sortName + "/sort", "1", str(f)])
        lst = out.splitlines(True)
        s = lst[len(lst)-1]
        print "Spended for sort " + s[0: len(s)-2] + " ms"
        print "------------------------------------------"

#Elementary sort
runBenchmark(16, "bubble")

runBenchmark(16, "comparisonestimation")

runBenchmark(16, "shell")

#Advanced
runBenchmark(22, "mergebase")

runBenchmark(22, "binqsort")

runBenchmark(22, "pqsort")
