stack=['E']
rules={'idE':'T e', 'numE':'T e', '(E':'T e',
       '+e':'+ T e', '-e':'- T e', ')e':'', 'e':'',
       'idT':'F t', 'numT':'F t', '(T':'F t',
       '+t':'',  '-t':'', '*t':'* F t', '/t':'/ F t', 't':'', ')t':'',
       'idF':'id', 'numF':'num', '(F':'( E )'
       }
fl = True

#s = input().split()[::-1]
s = 'id + num * ( num + id )'.split()[::-1]
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