def number_of_divisors(x):
  count = 0
  for i in range(x):
    if x%(i+1)==0:
      count+=1
  return count

with open('data.txt', 'w') as f:
    for i in range(1, 1000001):
        f.write(str(i)+" : "+ str(number_of_divisors(i))+ '\n' ) 