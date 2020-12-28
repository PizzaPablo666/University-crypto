import random

alphabet = "abcdefghijklmnopqrstuvwxyz"
key = ""
new_key = ""
lower_key = ""
result_key = ""
mapping = {}

print("Enter the key")
key = input()


# Processing the key
# Make all letters lowercase
lower_key = key.lower();
# Remove digits, whitespace, signs
for i in range(0,len(key)):
    if ((lower_key[i]>='a' and lower_key[i]<='z') or (lower_key[i]>='A' and lower_key[i]<='Z')):
        new_key += lower_key[i]
# Remove repeated chars
result_key =  "".join(dict.fromkeys(new_key))

print(result_key)

print(mapping)

# option -> random, a-z, z-a 
option = ""

print("Enter the continuation")
print("It should be a-z or z-a or random")
valid = False
# option num , 0 = random, 1 = a-z, 2 = z-a
option_num = 0
while valid == False:
    option = input()
    if option == "random":
        option_num = 0
        valid = True
    elif option == "a-z":
        option_num = 1
        valid = True
    elif option == "z-a":
        option_num = 2
        valid = True
    else:
        print("Wrong option try again")


# Continuing the key

ascii_letters = "abcdefghijklmnopqrstuvwxyz"
for i in ascii_letters:
    if i in result_key:
        ascii_letters = ascii_letters.replace(i,"")

   
res_key_len = len(result_key)
i = res_key_len
if option_num == 0:
    while i < 26:
        result_key += random.choice(ascii_letters)
        ascii_letters = ascii_letters.replace(result_key[i],'',1)
        i+=1
elif option_num == 1:
    for i in ascii_letters:
        result_key += i
elif option_num == 2:
    ascii_letters = ascii_letters[::-1]
    for i in ascii_letters:
        result_key += i


# Mapping
i = 0
for x in result_key:
    mapping[alphabet[i]] = x
    i+=1

print(mapping)

# message encryption

print("Enter you message (more is more)")
msg = input()

lower_msg = ""
new_msg = ""
# Make all letters lowercase
lower_msg = msg.lower();
# Remove digits, whitespace, signs
for i in range(0,len(msg)):
    if (lower_msg[i]>='a' and lower_msg[i]<='z'):
        new_msg += lower_msg[i]

i = 0
encrypted = ""
while i < len(new_msg):
    encrypted += mapping[new_msg[i]]
    i+=1

print("Key = " + result_key) 

print("Cipher = " + encrypted)
    
file1 = open("cipher","w")
file1.write(encrypted)
file1.close()

            
        



