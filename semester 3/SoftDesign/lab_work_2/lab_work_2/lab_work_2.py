def task_1(L):
    print("TASK 1. Список четных элементов списка L.")
    l = []
    for k in L:
        try:
            num = int(k)
            l.append(num)
        except ValueError:
            pass
    print("  L =", L)
    print('  res =',[i for i in l if i%2==0])

def task_2(L):
    print("TASK 2. Список элементов списка L с четными индексами.")
    print("  L =", L)
    print('  res =', L[::2])

def task_3(L):
    print("TASK 3. Список положительных элементов списка L.")
    print("  L =", L)
    l = []
    for k in L:
        try:
            num = float(k)
            l.append(k)
        except ValueError:
            pass
    print('  res =',[i for i in l if float(i)>0])

def task_4(L):
    print("TASK 4. Список множеств элементов, которые дают одинаковый остаток при делении на положительное число m.")
    print("  L =", L)
    print('  res =',[{j for j in L if j%L[0]==i} for i in range(L[0])])

def task_5(D):
    print("TASK 5. писок сумм ключей и соответствующих им значений словаря D, в случае если и ключ и значение являются числами. ")
    print("  D = ", D)
    print('  res =',[key+D.get(key) for key in D if type(key)==int and type(D.get(key))==int ])

def task_6(L):
   print("TASK 6. Cписок таких пар (кортежей из двух элементов) значений из списка чисел L, что первое значение строго меньше второго. ")
   print("  L =", L)
   print('  res =',[(L[i], L[j]) for i in range(len(L)) for j in range(len(L)) if L[i] < L[j]])

def task_7(L):
    print("TASK 7. Словарь, ключами которого служат элементы списка L с четными индексами, а значениями – соответствующие элементы с нечетными индексами.")
    print("  L =", L)
    print('  res =',{L[a]:L[a+1] for a in range(0,len(L),2)})

L = ['a',1,-2,1.2]
task_1(L);
task_2(L);
task_3(L);
m=[5,1, 2, 3, 4, 5, 6, 7]
task_4(m);
dict= {1:2,'a':3,-1:1,3:'a'}
task_5(dict)
s=[3,4.1,2];
task_6(s)
l=[1,2,3,4]
task_7(l)