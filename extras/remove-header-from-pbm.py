

xxdtest = "xxdtest.pbm"
xxdtestnew = "xxdtestnew.c.in"

index = -1
a = None

with open(xxdtest, "rb") as f:
    a = f.read()
    print(hex(a[3]))
    counter = 0
    if a[3] == 0x23:
        for i in range(4,len(a)):
            if a[i] == 0x0A:
                counter = counter + 1
                if counter == 2:
                    index = i + 1
                    break

with open(xxdtestnew, "wb") as fw:
    for j in range(index, len(a)):
        fw.write(a[j].to_bytes(1, byteorder='big'))
