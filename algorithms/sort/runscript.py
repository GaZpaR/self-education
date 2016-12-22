#!/usr/bin/python
import subprocess

def runBenchmark(power, sortName):
    print "------------------------------------------"
    print "| Sort type: " + sortName + " |"
    print "------------------------------------------"
    for arraySize in range(5,power):
        f = pow(2, arraySize)
        print "Quantity of elements in array: " + str(f)
        out = subprocess.check_output(["./" + sortName + "/sort", "1", str(f)])
        resultList = out.splitlines(True)
        s = resultList[len(resultList)-1]
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
