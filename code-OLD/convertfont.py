import sys

flag = False

filename = sys.argv[1]
new_filename = filename + "-converted.c"

with open(filename, 'r') as f:
    with open(new_filename, 'w') as ff:
        for line in f:
            if flag:
                ff.write(line[14:])
            elif 'unsigned' in line:
                ff.write(line)
                flag = True
        ff.write("};\n")



    
