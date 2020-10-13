a=int(input("wprowadz szerokosc "))
b=int(input("wprowadz wysokosc "))
for i in range (b):
    if (i == 0 or i == b-1):
        for g in range (a):
            print ("-",end="")
    