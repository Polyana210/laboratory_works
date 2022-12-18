
from colorama import Fore


class Node:
    key = None
    parent = None 
    child = None  
    left = None   
    right = None 
    degree = 0  

    def __init__(self, value):
        self.key = value

class Heap_F:
    size = 0
    min_node = None

    def insert(self, value):
        new_node = Node(value)
        if self.size == 0 :
            new_node.left = new_node
            new_node.right = new_node
            self.min_node = new_node
        else:
            preR = self.min_node.right
            preR.left = new_node
            new_node.right = preR 
            self.min_node.right = new_node
            new_node.left = self.min_node
        if new_node.key < self.min_node.key:
            self.min_node = new_node
        self.size+=1

    def get_min(self):
        return 'Min Element' + str(self.min_node.key)

    def merge(self,dictionary,new_temp_dict,temp):
        while dictionary[new_temp_dict.degree] is not None:
            if dictionary[new_temp_dict.degree].key< temp.key:
                new_temp_dict=dictionary[new_temp_dict.degree]
                Rchild=new_temp_dict.child.right
                temp.right=Rchild
                Rchild.left=temp
                new_temp_dict.child.right=temp
                temp.left=new_temp_dict.child
                dictionary[new_temp_dict.degree]=None
                new_temp_dict.degree+=1   
                temp=new_temp_dict      
                new_temp_dict=temp    
            else:
                Rchild=new_temp_dict.child.right
                dictionary[new_temp_dict.degree].right=Rchild
                Rchild.left=dictionary[new_temp_dict.degree]
                temp.child.right=dictionary[new_temp_dict.degree]
                dictionary[new_temp_dict.degree].left=temp.child
                dictionary[new_temp_dict.degree]=None
                new_temp_dict.degree+=1
        return new_temp_dict

    def del_min(self):
        if self.size == 0: return
        if self.size == 1: 
            self.min_node = None
            self.size == 0
            return
        if self.min_node.child == None:
            new_temp = self.min_node.right
            dictionary = { 0: None, 1:None,2: None, 3:None,4: None, 5:None,6: None, 7:None,8: None, 9:None,10: None, 11:None,}
            while new_temp!= self.min_node:
                temp = new_temp
                new_temp=new_temp.right
                temp.right=None
                temp.left=None
                if dictionary[temp.degree] is None:
                    dictionary[temp.degree]=temp
                elif dictionary[temp.degree] is not None:
                    if dictionary[temp.degree].key< temp.key:
                        if dictionary[temp.degree].child is not None:
                            new_temp_dict = dictionary[temp.degree]                       
                            new_temp_dict=self.merge(dictionary,new_temp_dict,temp)                                                      
                            dictionary[new_temp_dict.degree]=new_temp_dict
                        else:
                            if dictionary[temp.degree].key < temp.key:
                                new_temp_dict = dictionary[temp.degree]
                                dictionary[temp.degree] = None 
                                temp.right=temp                            
                                temp.left=temp
                                new_temp_dict.child= temp
                                temp.parent = new_temp_dict
                                new_temp_dict.degree+=1
                                temp = new_temp_dict                                
                                new_temp_dict=self.merge(dictionary,new_temp_dict,temp)                              
                            dictionary[new_temp_dict.degree]=new_temp_dict                         
                    else:    
                        if temp.child is not None:
                            new_temp_dict=dictionary[temp.degree]                         
                            new_temp_dict=self.merge(dictionary,new_temp_dict,temp)
                            dictionary[new_temp_dict.degree]=new_temp_dict
                        else:
                            temp.child = dictionary[temp.degree]
                            dictionary[temp.degree].right=dictionary[temp.degree]
                            dictionary[temp.degree].left=dictionary[temp.degree]
                            dictionary[temp.degree].parent = temp
                            new_temp_dict=temp
                            dictionary[temp.degree]=None
                            new_temp_dict.degree+=1                       
                            new_temp_dict=self.merge(dictionary,new_temp_dict,temp)
                            dictionary[new_temp_dict.degree]=new_temp_dict              
            d = list()
            for keys in dictionary:
                if dictionary[keys]!=None:
                    d.append(dictionary[keys].key)
            d.sort()
            for keys in dictionary:
                if dictionary[keys]!=None and dictionary[keys].key == d[0]:
                    self.min_node = dictionary[keys]
                    self.min_node.right=self.min_node 
                    self.min_node.self=self.min_node 
                    dictionary[keys]= None
                    break
            for keys in dictionary:
                if dictionary[keys]!=None:
                    Rprev= self.min_node.right
                    dictionary[keys].right = Rprev
                    Rprev.left = dictionary[keys]
                    dictionary[keys].left= self.min_node
                    self.min_node.right=dictionary[keys]
        else:
            fch=self.min_node.child
            lch=self.min_node.child.left
            lch.right=self.min_node.right
            self.min_node.right.left=lch
            fch.left=self.min_node
            self.min_node.right=fch          
            self.min_node.child.parent=None
            self.min_node.child=None
            new_temp = self.min_node.right
            dictionary = { 0: None, 1:None,2: None, 3:None,4: None, 5:None,6: None, 7:None,8: None, 9:None,10: None, 11:None,12:None,13:None}
            while new_temp!= self.min_node:
                temp = new_temp
                new_temp = new_temp.right
                if dictionary[temp.degree] is None:
                    dictionary[temp.degree]=temp
                elif dictionary[temp.degree] is not None:
                    if dictionary[temp.degree].key< temp.key:
                        if dictionary[temp.degree].child is not None:
                            new_temp_dict = dictionary[temp.degree]
                           
                            new_temp_dict=self.merge(dictionary,new_temp_dict,temp)
                            dictionary[new_temp_dict.degree]=new_temp_dict                    
                        else:
                            if dictionary[temp.degree].key < temp.key:
                                new_temp_dict = dictionary[temp.degree]
                                dictionary[temp.degree] = None            
                                temp.right=temp                           
                                temp.left=temp
                                new_temp_dict.child= temp
                                temp.parent = new_temp_dict
                                new_temp_dict.degree+=1
                                temp = new_temp_dict                            
                                new_temp_dict=self.merge(dictionary,new_temp_dict,temp)
                            dictionary[new_temp_dict.degree]=new_temp_dict                         
                    else:    
                        if temp.child is not None:
                            new_temp_dict=dictionary[temp.degree]                         
                            new_temp_dict=self.merge(dictionary,new_temp_dict,temp)
                            dictionary[new_temp_dict.degree]=new_temp_dict
                        else:
                            temp.child = dictionary[temp.degree]
                            dictionary[temp.degree].right=dictionary[temp.degree]
                            dictionary[temp.degree].left=dictionary[temp.degree]
                            dictionary[temp.degree].parent = temp
                            new_temp_dict=temp
                            dictionary[temp.degree]=None
                            new_temp_dict.degree+=1
                            new_temp_dict=self.merge(dictionary,new_temp_dict,temp)
                            dictionary[new_temp_dict.degree]=new_temp_dict               
            d = list()
            for keys in dictionary:
                if dictionary[keys]!=None:
                    d.append(dictionary[keys].key)
            d.sort()
            for keys in dictionary:
                if dictionary[keys]!=None and dictionary[keys].key == d[0]:
                    self.min_node = dictionary[keys]
                    self.min_node.right=self.min_node 
                    self.min_node.self=self.min_node 
                    dictionary[keys]= None
                    break
            for keys in dictionary:
                if dictionary[keys]!=None:
                    Rprev= self.min_node.right
                    dictionary[keys].right = Rprev
                    Rprev.left = dictionary[keys]
                    dictionary[keys].left= self.min_node
                    self.min_node.right=dictionary[keys]
        self.size-= 1

    def print_heap(self):
        if self.min_node == None: 
            print('\n\nFree Heap') 
            return
        level='  '
        count=1
        print(Fore.RED +' *' + str(self.min_node.key))

        if self.min_node.child!=None:
            print_child(self.min_node.child,self.min_node.child,level,' └  ',count)
            
        temp = self.min_node

        while temp.right!=self.min_node:
            print()
            temp=temp.right 
            print(Fore.MAGENTA+' *'+str(temp.key))
            if temp.child!=None:
                print_child(temp.child,temp.child,level,' └  ',count)   
                print(Fore.BLACK+'')               

def print_child(start,self,level,spec,count):
    
    print(Fore.MAGENTA+level+spec[:-2]+str(self.key))

    if self.child!=None:
        count+=1
        spec=spec[:-3]+('│'+level)
        spec=spec[:-3]+' '
        print_child(self.child, self.child,level,spec+' └  ',count)

    if self.right == start:
        return 

    print_child(start, self.right,level,' └  ',count)
    

def insertation(Heap):
    n = input('How Many Elements to Add: ')
    for _ in range(int(n)):
        Heap.insert(int(input('Input Element For Addiction: ')))

Heap = Heap_F()
print('\n\n\n'+Fore.MAGENTA+' Fibonacci Heap')
print(Fore.BLACK+'',end='')
while(True):
    print(Fore.BLACK+'')
    cm=input('\n\n 1.Add Elements \n 2.Delete Min Element \n 3.Print Heap \n 0.Exit\n\n\n\n Input Command:')
    if cm=='0':
        break
    elif cm=='1':
        insertation(Heap)
    elif cm=='2':
        Heap.del_min()
    elif cm=='3':
        Heap.print_heap()