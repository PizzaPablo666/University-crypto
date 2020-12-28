import matplotlib.pyplot as plt
from matplotlib import colors
from matplotlib.ticker import PercentFormatter
import sys
import numpy as np

file1 = open(sys.argv[1],"r")
lines = ""
lines = file1.readlines()
file1.close()

cipher = lines[0]

ascii_char = "abcdefghijklmnopqrstuvwxyz"

print("--> Enter the key size")
key = input("--> ")
key = int(key)



dictlist = [dict() for x in range(key)]
arr = ["" for x in range(key)]
curr_str = ""


#the key is poe

i = 0
j = 0
valid = False
while(j != key):
    print("--> ", end = '')
    valid = True
    while(i < len(cipher)):
        print(cipher[i],end='')
        if (i+key) >= len(cipher): break
        else : i = i + key
        curr_str += cipher[i]
    print('\n')
    arr[j] = curr_str
    curr_str = ""
    j +=1
    i = j

i = -1
while i != key:
    ascii_len = len(ascii_char)
    j = 0
    for j in ascii_char:
        dictlist[i][j] = 0

    text = arr[i]
    count = 0


    # count each letter in cipher
    j = 0
    for j in text:
        dictlist[i][j] = dictlist[i][j] + 1
        count += 1
    j = 0
    for j in dictlist[i]:
        dictlist[i][j] = dictlist[i][j] * 100 / count

    i+=1
#print(dictlist)

i = 0
while i == 0:
    num = input("Enter the number from 1 to key -> ")
    num = int(num)
    if (num != 0 and num != 1 and  num != 2):
        print("Wrong range try again")
    else :
        width = 1.0
        plt.bar(dictlist[num].keys(), dictlist[num].values(), width, color = 'g')
        plt.show()


    
