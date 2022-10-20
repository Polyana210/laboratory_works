stack = ['0']
rul_num =['E+T', 'E-T', 'T', 'T*F', 'T/F', 'F', 'i', 'n', '(E)']
rules = {'E+T':'E', 'E-T':'E', 'T':'E', 'T*F':'T', 'T/F':'T', 'F':'T', 'id': 'F', 'num': 'F', '(E)':'F'}
shift = {'0(':'4', '0id':'5', '0num':'6',
          '1+':'8', '1-':'7', 
          '2*':'9', '2/':'10', 
          '4(':'4', '4id':'5', '4num':'6',
          '7(':'4', '7id':'5', '7num':'6',
          '8(':'4', '8id':'5', '8num':'6',
          '9(':'4', '9id':'5', '9num':'6',
          '10(':'4', '10id':'5', '10num':'6',
          '11+':'8', '11-':'7', '11)':'16',
          '12*':'9', '12/':'10', 
          '13*':'9', '13/':'10'}

reduce = {'2+':'3', '2-':'3', '2(':'3','2$':'3',
          '3+':'6', '3-':'6', '3*':'6', '3/':'6','3(':'6','3$':'6',
          '5+':'7', '5-':'7', '5*':'7', '5/':'7','5(':'7','5$':'7',
          '6+':'8', '6-':'8', '6*':'8', '6/':'8','6(':'8','6$':'8',
          '12+':'2', '12-':'2', '12(':'2','12$':'2',
          '13+':'1', '13-':'1', '13(':'1','13$':'1',
          '14+':'4', '14-':'4', '14*':'4', '14/':'4','14(':'4','14$':'4',
          '15+':'5', '15-':'5', '15*':'5', '15/':'5','15(':'5','15$':'5',
          '16+':'6', '16-':'6', '16*':'6', '16/':'6','16(':'6','16$':'6'
          }

goto = {'0E':'1', '0T':'2', '0F':'3',
        '4E':'11', '4T':'2', '4F':'3',
        '7T':'12', '7F':'3',
        '8T':'13', '8F':'3',
        '9F':'14', '10F':'15'}
inp = []
str = (input()+' $').split()[::-1]
while True:
    s = stack[-1]
    a = str[-1]
    if ((s+a) in shift.keys()):
        stack.append(shift[s+a])
        inp.append(a)
        str.pop()
    elif (((s+a) in reduce.keys())):
        numb = rul_num[int(reduce[s+a])-1]
        l1 =[]
        for i in range(len(numb)):
            stack.pop()
            l1.append(inp.pop())
        l = ''.join(l1[::-1])
        s = stack[-1]
        stack.append(goto[s + rules[l]])
        inp.append(rules[l])
    elif (s+a=='1$'):
      fl=True
      break
    else:
      fl = False
      break

print(fl)