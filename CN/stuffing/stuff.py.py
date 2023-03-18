import PyPDF2
import random
pdfFileObj = open('Lorem_ipsum.pdf', 'rb')
pdfReader = PyPDF2.PdfReader(pdfFileObj)
pageObj = pdfReader.pages[0]  
file_pdf = pageObj.extract_text()
pdfFileObj.close()
ascii_string = ""
binary_string = ""
for ch in file_pdf:
    ascii_string += str(ord(ch))
    binary_string += str(bin(ord(ch)))[2:]  

with open('ascii.txt','w') as f:
    f.write(ascii_string)
with open('binary.txt','w') as f:
    f.write(binary_string)

#1. Character Count
start = 0
end = 0
packet_string = ""
while end<len(file_pdf):
    power = random.randint(1,8)
    end += 2**power
    packet = str(2**power)+file_pdf[start:end]
    start = end
    packet_string = packet_string + packet + "\n\n"


with open('char_count.txt','w') as f:
    f.write(packet_string)

#2. Bit Stuffing
with open('binary.txt','r') as f:
    binary = f.read()
    rem = len(binary)%128
    if(rem != 0):
        binary = binary + '1' + '0'*(128 - rem-1)
    bit_stuff = ""
    start = 0
    for bin in binary:
        if(len(bit_stuff) <= len(binary)):
            bit_stuff = bit_stuff + binary[start:start+8] + '0'
            start = start + 9

with open('bit_stuff.txt','w') as f:
    f.write(bit_stuff)

#2. Byte Stuffing
with open('binary.txt','r') as f:
    binary = f.read()
    byte_stuff = ""
    start = 0
    end = 0
    while end<len(binary):
        power = random.randint(1,8)
        end += 2**power
        packet = binary[start:end]
        start = end
        byte_stuff = byte_stuff + packet + "\n"

with open('byte_stuff.txt','w') as f:
    f.write(byte_stuff)