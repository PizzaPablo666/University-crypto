import matplotlib.pyplot as plt
from matplotlib import colors
from matplotlib.ticker import PercentFormatter
import sys
import numpy as np


# Reading cipher from a command line argument file
file1 = open(sys.argv[1],"r")
cipher = ""
cipher = file1.readlines()
file1.close()

ascii_char = "abcdefghijklmnopqrstuvwxyz"
percent = {}

# filling alphabet in percent dic
ascii_len = len(ascii_char)
i = 0
for i in ascii_char:
    percent[i] = 0

text = cipher[0]
count = 0

# count each letter in cipher
for i in text:
#    print ("I am here")
#    print(i)
#    print(percent[i])
    percent[i] = percent[i] + 1
    count += 1

print(percent)
print(count)
i=0
for key in percent:
    percent[key] = percent[key] * 100 / count


print(percent)
width = 1.0
plt.bar(percent.keys(), percent.values(), width, color = 'g')
plt.show()
