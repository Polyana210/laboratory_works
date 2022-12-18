# Вариант 2

stack=['A']
rules={'aA':'B c A a', 'bA':'b B b', 'cA':'B c A a',
       'aB':'a', 'cB':'c A c', 'a':'', 'b':'', 'c':'', 'A':''}
fl = True

s = input().split()[::-1]
for i in range(len(s)):
  if s[i]=='1':
    s[i] = 'a'
  elif s[i]=='2':
    s[i] = 'b'
  else:
     s[i]='c'
while len(stack)!=0 and fl==True:
    if len(s)>0:
        si = s[-1]
    else: si = ""
    elem = si + stack.pop()
    if elem not in rules.keys():
        fl=False
        break
    stack = stack + rules[elem].split()[::-1]
    if len(stack)>0 and stack[-1]==si:
         stack.pop()
         if len(s)>0:
             s.pop()
if fl:
    print("Result: YES")
else:
    print("Result: NO")