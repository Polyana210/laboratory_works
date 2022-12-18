'''Вариант 2'''
import collections
class C1:
    k = None
    d = None

    def __init__(self, a=0, b=0):
       self.d = a-b

    def decorator(f):
        def arguments(*args): 
            f(*args)
        return arguments
    
    @decorator
    def __call__(self, *nums):
      self.k = len(nums)
    
    def __mul__(self, other):
        res = C1()
        res.d= min(self.d, other.k)
        res.k = self.k - other.k
        return res
     
class C2 (C1):
  def __init__(self, a= 0, b=0):
    C1.__init__(self, a, b)
  
  def __call__(self, *nums):
    C1.__call__(self, *nums)

  def __eq__(self, other):
    if self.d * other.k + self.d**2==other.d**2 + self.k * other.d:
      return True
    else:
      return False

# 1) создание экземляра класса С1
elem_1 = C1(2, 2)
# 2) вызов декоратора экземляра класса С1
elem_1(1, 2, 3)
# 3) создание экземляра класса С1
elem_2 = C1(3, 4)
elem_2(2, 4, 6, 8)
# 4) умножение экземпляров класса С1
Z = elem_1*elem_2
# 5) создание экземляра класса С2
elem_3 = C2(2, 2)
elem_3(1, 2, 3)
# 6) создание экземляра класса С2
elem_4 = C2(3, 4)
elem_4(2, 4, 6, 8)
# 7) сравнение экземляров класса С2
elem_3 == elem_4
# 8) проверка на хеширование экземляра класса С2
isinstance(elem_3, collections.abc.Hashable)

