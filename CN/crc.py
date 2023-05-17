def crc(diff):
    dividend = list(int(ch) for ch in list(input("Enter the data: ")))
    divisor = list(int(ch) for ch in list(input("Enter divisor: ")))

    if diff == 0:
        for i in range(len(divisor) - 1):
            dividend.append(0)

    remainder = []
    lst = dividend[0:len(divisor)]

    for i in range(len(dividend)-len(divisor)+1):
        if lst[0] == 1:
            comp = divisor
        else: comp = list(0 for j in range(len(divisor)))
        for c in range(len(divisor)):
            if lst[c] == comp[c]: remainder.append(0)
            else: remainder.append(1)
        lst = remainder[1:]
        if i!=(len(dividend)-len(divisor)):
            lst.append(dividend[i+len(divisor)])
        remainder.clear()
    return lst,dividend


print("For initial data: ")
l,d = crc(0)
rem = "".join(map(str,l))
print("Remainder: ",rem)
enc_data = d.copy()
enc_data = enc_data[:len(d)-len(l)] + l
print("Encoded data: ","".join(map(str,enc_data)))
print("For transmitted data: ")
l2,d2 = crc(1)
rem2 = int("".join(map(str,l2)))
print("Remainder: ",rem2)
if(rem2 != 0): print("Error in transmission")
else: print("No error")