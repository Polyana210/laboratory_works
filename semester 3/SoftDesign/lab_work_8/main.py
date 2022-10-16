import class_decomposition 
print("Выберите действие:")
print('1) Создать элемент с помощью числа ')
print('2) Создать элемент с помощью пар ')
x = int(input())
if x==1:
  dec=class_decomposition.canonical_decomposition_number(int(input("Введите число  ")))
elif x==2:
  val =dict()
  length = int(input("Введите количество пар"))
  for i in range(length):
    a = int(input("Введите простое число "))
    val[a] = int(input("Введите его степень "))
  dec=class_decomposition.canonical_decomposition_number(val)
else:
  exit()
while True:
  print()
  print("Выберите действие:")
  print('1) Создать итератор и пройти по парам ')
  print('2) Преобразовать в строку (str) ')
  print('3) Преобразовать в строку (repr) ')
  print('4) Сложение ')
  print('5) Вычитание ')
  print('6) Умножение ')
  print('7) Целочисленное деление ')
  print('8) Преобразовать в число (int) ')
  x = int(input())
  print()
  if x==1:
    it = iter(dec)
    print(next(dec))
    print(next(dec))
    print("...")
  elif x==2:
    print(str(dec))
  elif x==3:
    print(repr(dec))
  elif x==4:
    a = int(input("Введите число для сложения "))
    print((dec+a).number)
  elif x==5:
    a = int(input("Введите число для вычитания "))
    print((dec-a).number)
  elif x==6:
    a = int(input("Введите число для умножения "))
    print((dec*a).number)
  elif x==7:
    a = int(input("Введите число для деления "))
    print((dec*a).number)
  elif x==8:
    print(int(dec))
  else:
    exit()