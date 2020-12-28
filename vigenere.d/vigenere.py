
import re

def GetKey(val):
   for key, value in dic.items():
      if val == value:
         return key

# Enter Plaintext and Key
plaintxt = ""
key = ""
ciphertxt = ""

print("--> Enter the plaintext <--")
plaintxt = input("--> ")

print("--> Enter the key <--")
key = input("--> ")

# Make plaintext and key lowercase
modif_plaintxt = plaintxt.lower()
modif_key = key.lower()

# Make modified plaintext without spaces and special signs
modif_plaintxt = re.sub('[^a-z]+', '', modif_plaintxt)
modif_key = re.sub('[^a-z]+', '', modif_key)

# Make key for plaintext
all_part = int(len(modif_plaintxt) / len(modif_key))
partial =  len(modif_plaintxt) % len(modif_key)

modif_keytxt = (''.join(modif_key) * all_part)
modif_keytxt += modif_key[:partial]
print(modif_keytxt)

# Make vigenere table A-Z
alphabet = "abcdefghijklmnopqrstuvwxyz"
encrypted = ""

j = 0
dic = {}
for i in alphabet:
    dic[i] = j
    j += 1

#print(dic)

for i in range(0,len(modif_plaintxt)):
    #print(dic[modif_plaintxt[i]])
    #print(dic[modif_keytxt[i]])
    #print("sum = ", dic[modif_plaintxt[i]] + dic[modif_keytxt[i]])
    encrypted += GetKey((dic[modif_plaintxt[i]] + dic[modif_keytxt[i]])%26) 
print("encrypted = ", encrypted)

cipher = open("cipher.txt","w")
cipher.write(encrypted)

