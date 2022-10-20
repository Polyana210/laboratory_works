import functions 
# Task 1
# Напишите функцию вычисления наибольшего общего делителя с помощью алгоритма Евклида.
print("TASK 1")
num1, num2 = int(input("Input num1: ")), int(input("Input num2: "))
print("GCD =",functions.Task1(num1, num2))

# Task 2
# Напишите функцию вычисления наибольшего общего делителя с помощью алгоритма Евклида.
print("TASK 2")
print("Input parametrs:")
print("GCD =",functions.Task2([int(i) for i in input().split()]))

# Task 3
# Напишите функцию поочередно возвращающую все простые делители данного числа.
print("TASK 3")
print('Simple divisors:',*functions.Task3(int(input("Input num: "))))

# Task 4
# Напишите функцию-декоратор, которая позволяет из функции f, принимающей 2 аргумента,
# получить функцию принимающую произвольное количество аргументов, 
# выполняющую свертку последовательности своих аргументов с помощью функции f.
print("TASK 4")
print("Input parametrs:")
print('Convolution =', functions.Task4(*[int(i) for i in input().split()]))