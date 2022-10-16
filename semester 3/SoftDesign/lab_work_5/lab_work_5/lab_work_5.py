def NOD(num1, num2):
    while num1 != 0 and num2 != 0:
        if num1 >= num2:
            num1 %= num2
        else:
            num2 %= num1
    return num1 or num2

num1, num2 = int(input("Input num1: ")), int(input("Input num2: "))
print(NOD(num1, num2))