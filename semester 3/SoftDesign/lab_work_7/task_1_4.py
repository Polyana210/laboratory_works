import math
def f(x):
  try:
    a = 1/(math.sqrt(x**2 -1))
  except ValueError:
    print("Обработано исключение ValueError внутри функции")
  return a

for i in range(101):
  try:
    print("f =", f(float(input("Введите число "))))
  except ValueError:
    print("Обработано исключение ValueError")
  except ZeroDivisionError:
    print("Обработано исключение ZeroDivisionError")
  except OverflowError:
    print("Обработано исключение OverflowError")
  except KeyboardInterrupt:
    print("Обработано исключение KeyboardInterrupt")
    print("Осталось итераций: ", 99-i)