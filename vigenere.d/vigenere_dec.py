import re

def GetKey(val):
   for key, value in dic.items():
      if val == value:
         return key


# Read from cipher file
cipher_file = open("cipher.txt","r")
Lines = cipher_file.readlines()
cipher = Lines[0]

# Enter the key
# Enter Plaintext and Key
key = ""
plaintxt = ""

print("--> Enter the key <--")
key = input("--> ")

# Make plaintext and key lowercase
modif_key = key.lower()

# Make modified key without spaces and special signs
modif_key = re.sub('[^a-z]+', '', modif_key)

# Make key for cipher
all_part = int(len(cipher) / len(modif_key))
partial =  len(cipher) % len(modif_key)

modif_keytxt = (''.join(modif_key) * all_part)
modif_keytxt += modif_key[:partial]
print(modif_keytxt)


# Make dictionary from alphabet and map with 0-25 nums
alphabet = "abcdefghijklmnopqrstuvwxyz"
j = 0
dic = {}
for i in alphabet:
    dic[i] = j
    j += 1

# Decrypting
for i in range(0,len(cipher)):
    plaintxt += GetKey((dic[cipher[i]] - dic[modif_keytxt[i]] + 26) % 26) 
print(plaintxt)


