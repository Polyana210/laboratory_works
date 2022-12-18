#  На банкет были приглашены N Очень Важных Персон (ОВП). Были поставлены 2 стола.
#  Столы достаточно большие, чтобы все посетители банкета могли сесть за любой из них. 
# Проблема заключается в том, что некоторые ОВП не ладят друг с другом и не могут сидеть за одним столом.
#  Вас попросили определить, возможно ли всех ОВП рассадить за двумя столами.
def analiz(t, color, enemies):
  for z in range(t,m):
    a = enemies[z][0]
    b = enemies[z][1]
    if color[a-1]==0:
      if color[b-1]==0:
        color[a-1] = 1
        color[b-1] = -1
        if not analiz(z+1, color, enemies):
          color[a-1] = -10
          color[b-1] = 1
          return analiz(z+1, color, enemies)
      else:
          color[a-1] = -color[b-1]
    else:
      if color[b-1]==0:
        color[b-1]=-color[a-1]
      else:
        if color[b-1]==color[a-1]:
          return False
  return True

n = int(input("Enter number of OVP "))
m = int(input("Enter number of enemies "))
color = []
enemies =[]
for i in range(n):
  color.append(0)
for i in range(m):
  enemies.append([int(i) for i in input().split()])
if n<=2:
  print("YES")
  exit()
if (analiz(0,color, enemies)):
  print("YES")
else:
  print("NO")