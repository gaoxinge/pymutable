import sys
from pymutable import *

# test int
a = 1
b = 2
print(a, id(a), sys.getrefcount(a))
mutate_int(a, b)
print(a, id(a), sys.getrefcount(a))

# test float
a = 1.0
b = 2.0
print(a, id(a), sys.getrefcount(a))
mutate_float(a, b)
print(a, id(a), sys.getrefcount(a))

# test complex
a = 1 + 2j
b = 3 + 4j
print(a, id(a), sys.getrefcount(a))
mutate_complex(a, b)
print(a, id(a), sys.getrefcount(a))

# test tuple
a = (1, 2, 3)
print(a, id(a), sys.getrefcount(a))
mutate_tuple_set_item(a, 0, 4)
print(a, id(a), sys.getrefcount(a))
