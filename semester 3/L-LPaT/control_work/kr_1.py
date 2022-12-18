# Вариант 2

def lang_1(str):
  if 'a' in str:
    str.remove('a')
  else: 
    return False
  if 'a' in str or 'b' in str:
    str.remove('b')
    if 'b' in str:
      return False
    return True
  else: 
    return False

def lang_2(str):
  if 'a' in str:
    str.remove('a')
  else: 
    return False
  while len(str)!=0:
    if 'a' in str:
      if 'b' in str:
        str.remove('b')
        str.remove('a')
      else:
        str.remove('a')
    else:
      return False
  return True

str = list(input())

if lang_1(str):
    print("LA")
elif lang_2(str):
    print("LB")
else:
  print("NONE OF THEM")