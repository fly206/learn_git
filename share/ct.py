#! /usr/bin/python3
# -*- encoding:UTF-8 -*-
import ctypes
ll = ctypes.cdll.LoadLibrary
lib = ll("./libmax.so")
i = lib.max(15,14,16)
print("***finish***"+str(i))

