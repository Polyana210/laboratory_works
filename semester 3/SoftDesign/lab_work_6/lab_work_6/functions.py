def Task1(num1, num2):
    while num1 != 0 and num2 != 0:
        if num1 >= num2:
            num1 %= num2
        else:
            num2 %= num1
    return num1 or num2

def Task2(numbers):
    a = numbers.pop()
    while len(numbers)!=0:
        a = Task1(a, numbers.pop())
    return a

def Task3(num):
    res =[]
    dev = [i for i in range(2, num+1) if num%i==0]
    for i in dev:
        counter = 0
        for k in range(2,i+1):
            if i%k==0:
                counter+=1
        if counter==1:
            res.append(i)
    return res


def Task4(*nums):
  sum = 0
  for n in nums:
      sum += n
  return sum




