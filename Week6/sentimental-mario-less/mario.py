import cs50 as cs

number = 0

while number < 1 or number > 8:
    number = cs.get_int("Height : ")




for i in range (1, number + 1):
    space = number - i
    print(" " * space + "#" * i)