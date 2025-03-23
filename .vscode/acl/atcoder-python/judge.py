import sys
# input
with open(sys.argv[1]) as testcase:
   input = list(map(int, testcase.readline().split()))
#output
with open(sys.argv[2]) as your_output:
    output = list(map(int, your_output.readline().split()))
#expected output(multiple)
with open(sys.argv[3]) as expected_output:
    expected = expected_output.readlines()
    expected = [list(map(int, x.split())) for x in expected]
    
assert NotImplementedError("Not implemented yet")