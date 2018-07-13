#! /usr/bin/python3
# -*- encoding:UTF-8 -*-

import os
from os import *
main= "./a.out"
# os.system("LD_LIBRARY_PATH=.")
if os.path.exists(main):
    rc = os.system(main)
    print("rc="+str(rc))
print("*"*10)
f = os.open(main)
data = f.readlines()
f.close()
print(data)
print("*"*10)
os.system(main)

