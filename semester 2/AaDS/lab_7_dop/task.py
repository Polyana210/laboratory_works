import os

def merge_sort(nums): 
    if len(nums) > 1: 
        mid = len(nums)//2
        left = nums[:mid] 
        right = nums[mid:]
        merge_sort(left) 
        merge_sort(right) 
        i = j = k = 0
        while i < len(left) and j < len(right): 
            if left[i] < right[j]: 
                nums[k] = left[i] 
                i+=1
            else: 
                nums[k] = right[j] 
                j+=1
            k+=1
        while i < len(left): 
            nums[k] = left[i] 
            i+=1
            k+=1
        while j < len(right): 
            nums[k] = right[j] 
            j+=1
            k+=1
    return nums

def main(S):
  f = open('first.txt', 'r')
  a = open('A.txt', 'w')
  b = open('B.txt', 'w')
  fl = True
  CurrentFile = a
  while fl:
      CurrList =[]
      for _ in range(S):
        j = f.readline()
        if j =="" or j =="\n":
          fl = False
          break
        if f:
          CurrList.append(int(j))
      merge_sort(CurrList)
      if len(CurrList)>0:
        for i in range(len(CurrList)):
          CurrentFile.write(str(CurrList[i])+'\n')
        CurrentFile.write("*"+'\n')
      if CurrentFile == a:
        CurrentFile = b
      else: 
        CurrentFile = a
  a.close
  b.close
  f.close
  

def merge(S, sfile):
  a = open('A.txt', 'r')
  b = open('B.txt', 'r')
  c = open('C.txt', 'a')
  d = open('D.txt', 'a')
  c.truncate(0)
  d.truncate(0)
  Size = S
  input1 = a
  input2 = b
  CurrentOutput = c
  fl = True
  while fl:
    j = input1.readline()
    k = input2.readline()
    if j=="'\n'" or k=="'\n'":
      break
    j =j[:-1]
    k= k[:-1]
    while j!='' and k!='':
      while j!='*' and k!='*':
        if int(j)<int(k):
          CurrentOutput.write(j+'\n')
          j = input1.readline()[:-1]
        else:
          CurrentOutput.write(k + '\n')
          k =input2.readline()[:-1]
      if j =="*":
        while k!='*':
          CurrentOutput.write(k + '\n')
          k =input2.readline()[:-1]
      else:
        while j!='*':
            CurrentOutput.write(j + '\n')
            j =input1.readline()[:-1]
      CurrentOutput.write("*\n")
      j = input1.readline()[:-1]
      k = input2.readline()[:-1]
      if CurrentOutput == a:
        a.close()
        b = open('B.txt', 'a')
        CurrentOutput = b
      elif CurrentOutput == b:
        b.close()
        a = open('A.txt', 'a')
        CurrentOutput = a
      elif CurrentOutput == c:
        c.close()
        d = open('D.txt', 'a')
        CurrentOutput = d
      elif CurrentOutput == d:
        d.close()
        c = open('C.txt', 'a')
        CurrentOutput = c
    if j =="":
        while k!='':
          CurrentOutput.write(k + '\n')
          k =input2.readline()[:-1]
    else:
        while j!='':
            CurrentOutput.write(j + '\n')
            j =input1.readline()[:-1]
    Size *=2
    if Size >= sfile:
      fl = False
      if CurrentOutput == a:
        a.close()
        b = open('B.txt', 'r')
        res = b 
      elif CurrentOutput == b:
          b.close()
          a = open('A.txt', 'r')
          res = a
      elif CurrentOutput == c:
          c.close()
          d = open('D.txt', 'r')
          res = d
      else:
          d.close()
          c = open('C.txt', 'r')
          res = c
      RESULT = open('result.txt', 'w')
      num = res.readline()[:-1]
      while num!='*':
        RESULT.write(num+'\n')
        num = res.readline()[:-1]
      RESULT.close()
      break
    if input1 == a:
        c.close()
        d.close()
        c = open('C.txt', 'r')
        d = open('D.txt', 'r')
        input1 = c
        input2 = d
        a.close()
        b.close()
        a = open('A.txt', 'a')
        b = open('B.txt', 'a')
        a.truncate(0)
        b.truncate(0)
        CurrentOutput = a
    else:
        a.close()
        b.close()
        a = open('A.txt', 'r')
        b = open('B.txt', 'r')
        input1 = a
        input2 = b
        c.close()
        d.close()
        c = open('C.txt', 'a')
        d = open('D.txt', 'a')
        c.truncate(0)
        d.truncate(0)
        CurrentOutput = c
  a.close()
  b.close()
  c.close()
  d.close()
  




S = 5 # чисел (вместимость оперативной памяти)
sfile = 100 # чисел (необходимо отсортировать)
main(S)
merge(S, sfile)