class canonical_decomposition_number:
  def __init__ (self, val):
        if type(val) == int:
            self.number = val
            self.decomposition = self.num_decomp(val)
        elif type(val) == dict:
            self.number = self.decomp_num(val)
            self.decomposition = val
        else:
            print("Непододящий тип")


  def num_decomp(self, num):
    decomp = dict()
    for i in list_devisors(num):
      count = 0
      a = num
      while a%i==0:
        count+=1
        a/=i
      decomp[i]=count
    return decomp


  def decomp_num(self, decomp):
    num = 1
    for i in decomp:
      num *= i**decomp[i]
    return num

  def __add__(self, other):
    if type(other)==int:
       res = canonical_decomposition_number(self.number+other)
    else:
       res = canonical_decomposition_number(self.number+other.number)
    return res
    
  def __sub__(self, other):
    if type(other)==int:
       res = canonical_decomposition_number(self.number-other)
    else:
       res = canonical_decomposition_number(self.number-other.number)
    return res
  
  def __mul__(self, other):
    if type(other)==int:
       res = canonical_decomposition_number(self.number*other)
    else:
       res = canonical_decomposition_number(self.number*other.number)
    return res
  
  def __floordiv__(self, other):
    if type(other)==int:
       res = canonical_decomposition_number(self.number//other)
    else:
       res = canonical_decomposition_number(self.number//other.number)
    return res

  def __iter__(self):
        self.n = 0
        return self

  def __next__(self):
        if self.n < len(self.decomposition):
            a = list((self.decomposition).keys())[self.n]
            result = str(a) + " : "+str(self.decomposition[a])
            self.n += 1
            return result
        else:
            return None

  def __str__(self):
    return str(self.number)
  
  def __int__(self):
    return self.number

  def __repr__(self):
    return("canonical_decomposition_number("+str(self.decomposition)+")")

def list_devisors(num):
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

