""" sentence = input("Enter a sentence: ") 
binary1 = ""
for ch in sentence:
    binary1 += '0'+str(bin(ord(ch)))[2:]"""

binary1 = '01100001'
binary = binary1[::-1] 
print(binary1)

r=0
while 2**r < len(binary)+r+1:
    r = r + 1
b=0
hamming_list = []
value_list = []
m = 0
for i in range(12):
    if i+1 == 2**b:
        hamming_list.append('P'+str(i+1))
        value_list.append('X')
        b +=1
    else: 
        hamming_list.append('D'+str(i+1))
        value_list.append(binary[m])
        m+=1

hamming_list.reverse()
print(hamming_list)

P1 = [3,5,7,9,11]
P2 = [3,6,7,10,11]
P4 = [4,5,6,7,12]
P8 = [8,9,10,11,12]
c1 = 0
c2 = 0
c4 = 0
c8 = 0
pairs = [(P1,c1),(P2,c2),(P4,c4),(P8,c8)]

def checkParity(pair):
    P,c = pair
    for index in P:
        if value_list[index-1] == '1':
            c+=1
    return P,c

for pair in pairs:
    P,c = checkParity(pair)
    set_parity = '1'
    if c%2==0: set_parity='0'

    if P==P1:
        value_list[0] = set_parity
    elif P==P2:
        value_list[1] = set_parity
    elif P==P4:
        value_list[3] = set_parity
    elif P==P8:
        value_list[7] = set_parity

val_disp = value_list.copy()
val_disp.reverse()
print(val_disp)