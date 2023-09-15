import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(('localhost', 3030)) # Привязываем серверный сокет к localhost и 3030 порту.
s.listen(2) # Начинаем прослушивать входящие соединения.
conn1, addr1 = s.accept() # Метод который принимает входящее соединение.
print('Connected to :', addr1[0], ':', addr1[1])

conn1.sendall("...Ждем подключение второго игрока...\n\r".encode('utf-8'))
conn2, addr2 = s.accept()
print('Connected to :', addr2[0], ':', addr2[1])
rules = "Вы попали в текстовую битву. Игроки атакуют по очереди, при атаке Вам доступны следующие приемы: 'удар слева', 'удар справа', 'удар в голову', 'подножка'. При защите у Вас есть следующие возможности: 'уклон слева', 'уклон справа', 'уклон головы', 'защита от подножки'. Готовы?\n\r"
conn1.sendall(rules.encode('utf-8'))
conn2.sendall(rules.encode('utf-8'))
conn1.recv(1024)
conn2.recv(1024)
score1, score2 = 0, 0
count =0
while score1-score2<10 and score2-score1<10:
  count+=1
  if count%2==1:
    conn1.sendall(('СЧЕТ: '+str(score1)+'/'+str(score2)+'\n\r').encode('utf-8'))
    conn2.sendall(('СЧЕТ: '+str(score2)+'/'+str(score1)+'\n\r').encode('utf-8'))
    conn1.sendall("Выберите действие для атаки: ".encode('utf-8'))
    conn2.sendall("Выберите действие для защиты: ".encode('utf-8'))
    action_attack = conn1.recv(1024).decode('utf-8')
    action_protect = conn2.recv(1024).decode('utf-8')
    if action_attack == "" or  action_protect == "":
      pass
    if (action_attack=='удар слева' and action_protect=='уклон слева') or (action_attack=='удар справа'and action_protect=='уклон справа') or (action_attack=='удар в голову'and action_protect=='уклон головы') or (action_attack== 'подножка' and action_protect=='защита от подножки'):
      conn1.sendall("Соперник уклонился\n\r".encode('utf-8'))
      conn2.sendall("Вам удалось уклониться\n\r".encode('utf-8'))
    else:
      conn1.sendall("Вы нанесли урон. Вам начислены очки\n\r".encode('utf-8'))
      conn2.sendall("Уклониться не вышло. Вам сняты очки\n\r".encode('utf-8'))
      score1+=5
      score2-=5
  else:
    conn2.sendall(('СЧЕТ: '+str(score1)+'/'+str(score2)+'\n\r').encode('utf-8'))
    conn1.sendall(('СЧЕТ: '+str(score2)+'/'+str(score1)+'\n\r').encode('utf-8'))
    conn2.sendall("Выберите действие для атаки: ".encode('utf-8'))
    conn1.sendall("Выберите действие для защиты: ".encode('utf-8'))
    action_attack = conn2.recv(1024).decode('utf-8')
    action_protect = conn1.recv(1024).decode('utf-8')
    if action_attack == "" or  action_protect == "":
      pass
    if (action_attack=='удар слева' and action_protect=='уклон слева') or (action_attack=='удар справа'and action_protect=='уклон справа') or (action_attack=='удар в голову'and action_protect=='уклон головы') or (action_attack== 'подножка' and action_protect=='защита от подножки'):
      conn2.sendall("Соперник уклонился\n\r".encode('utf-8'))
      conn1.sendall("Вам удалось уклониться\n\r".encode('utf-8'))
    else:
      conn2.sendall("Вы нанесли урон. Вам начислены очки\n\r".encode('utf-8'))
      conn1.sendall("Уклониться не вышло. Вам сняты очки\n\r".encode('utf-8'))
      score2+=5
      score1-=5
  action_attack = conn1.recv(1024).decode('utf-8')
  action_protect = conn2.recv(1024).decode('utf-8')
if score2>score1:
  conn2.sendall("Вы выиграли".encode('utf-8'))
  conn1.sendall("Вы проиграли".encode('utf-8'))
else:
  conn1.sendall("Вы выиграли".encode('utf-8'))
  conn2.sendall("Вы проиграли".encode('utf-8')) 
conn1.close()
conn2.close()