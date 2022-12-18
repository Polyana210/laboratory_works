import random

# класс одного узла дерева
class RedBlackNode:
    def __init__(self, val):
        self.red = False
        self.parent = None
        self.val = val
        self.left = None
        self.right = None

max_node = RedBlackNode(0)
max_d = 0
max_height = 0
max_height_node = RedBlackNode(0)
height = 0

# класс дерева
class RedBlackTree:
    def __init__(self):
        self.nil = RedBlackNode(0)
        self.nil.red = False
        self.nil.left = None
        self.nil.right = None
        self.root = self.nil

    # вставка
    def insert(self, val):
        new_node = RedBlackNode(val)
        new_node.parent = None
        new_node.left = self.nil
        new_node.right = self.nil
        new_node.red = True

        parent = None
        current = self.root
        while current != self.nil:
            parent = current
            if new_node.val < current.val:
                current = current.left
            elif new_node.val > current.val:
                current = current.right
            else:
                return

        new_node.parent = parent
        if parent == None:
            self.root = new_node
        elif new_node.val < parent.val:
            parent.left = new_node
        else:
            parent.right = new_node

        # Fix the tree
        self.fix_insert(new_node)
        
    # балансировка после вставки
    def fix_insert(self, new_node):
        while new_node != self.root and new_node.parent.red:
            if new_node.parent == new_node.parent.parent.right: # если папа правый потомок деда
                u = new_node.parent.parent.left  # дядя
                # дядя и папа красный -> дядя и папа черный,дед красный
                if u.red: 
                    u.red = False 
                    new_node.parent.red = False  
                    new_node.parent.parent.red = True
                    new_node = new_node.parent.parent
                else:
                # папа красный, дядя черный, левый потомок -> поворот вправо
                    if new_node == new_node.parent.left:
                        new_node = new_node.parent
                        self.rotate_right(new_node)
                # папа красный, дядя черный, правый потомок -> поворот влево
                    new_node.parent.red = False
                    new_node.parent.parent.red = True
                    self.rotate_left(new_node.parent.parent)
            else:
                u = new_node.parent.parent.right  # дядя
                # если папа левый потомок деда
                if u.red:
                # дядя и папа красный -> дядя и папа черный, дед красный
                    u.red = False
                    new_node.parent.red = False
                    new_node.parent.parent.red = True
                    new_node = new_node.parent.parent
                else:
                # папа красный, дядя черный, правый потомок -> поворот влево
                    if new_node == new_node.parent.right:
                        new_node = new_node.parent
                        self.rotate_left(new_node)
                # папа красный, дядя черный, левый потомок -> поворот вправо
                    new_node.parent.red = False
                    new_node.parent.parent.red = True
                    self.rotate_right(new_node.parent.parent)
        self.root.red = False

    # левый поворот
    def rotate_left(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.nil:
            y.left.parent = x

        y.parent = x.parent
        if x.parent == None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    # правый поворот
    def rotate_right(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.nil:
            y.right.parent = x

        y.parent = x.parent
        if x.parent == None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def __repr__(self):
        lines = []
        self.print_tree(self.root)
        return '\n'.join(lines)

    # вывод дерева в указанном виде
    def print_tree(self, node):
        def inner(node, *, last = True, pref = ''):
            if node is None:
              return
            print(pref + ('└─' + Fore.GREEN + 'R:'+Fore.BLACK if last else '├─'+ Fore.MAGENTA + 'L:'+Fore.BLACK ) + ((Fore.RED+str(node.val)+Fore.BLACK if node.red else str(node.val)) if node.val!=0 else "-"))
            inner(node.right, last = False, pref = pref + ('  ' if last else '│ '))
            inner(node.left, last = True, pref = pref + ('  ' if last else '│ '))
        inner(node) 

    # 
    def find_element(self, node, e):
      if node is not None:
          if e == node.val:
           # print()
            print(f"""Элемент {e} найден в дереве!""")
            print(node.val)
            return node
          elif e < node.val:
            self.find_element(node.left, e)
          else:
            self.find_element(node.right, e)
      else:
          print()
          print(f"""Element {e} is {'not found'.upper()} in the tree""")
          return None

    # прямой обход дерева
    def pre_order(self, root):
        if root:
            if root.val!=0: print(root.val, end=" ")
            self.pre_order(root.left)
            self.pre_order(root.right)

    # обратный обход дерева
    def post_order(self, root):
        if root:
            self.post_order(root.left)
            self.post_order(root.right)
            if root.val!=0: print(root.val, end=" ")

    # симметричный обход дерева
    def in_order(self, root):
        if root:
            self.in_order(root.left)
            if root.val!=0: print(root.val, end=" ")
            self.in_order(root.right)

    # поиск глубины узла
    def findDepth(self, node, x):
        if (node == None):
            return -1
        dist = -1
        if (node.val == x):
            return dist + 1
        dist = self.findDepth(node.left, x)
        if dist >= 0:
            return dist + 1
        dist = self.findDepth(node.right, x)
        if dist >= 0:
            return dist + 1
        return dist

    # поиск высоты узла
    def findHeightUtil(self, root, x):
        global height
        if (root == None):
          return -1  
        leftHeight = self.findHeightUtil(root.left, x)
        rightHeight = self.findHeightUtil(root.right, x)
        ans = max(leftHeight, rightHeight) + 1
        if (root.val == x):
            height = ans
        return ans

    # определение уровня узла
    def Level(self, root, X):
        if root is None:
            return 0
        q = []
        currLevel = 1
        q.append(root)
        while(len(q) > 0):
            size = len(q)
            for i in range(size):
                node = q.pop(0)
                if(node.val == X):
                    return currLevel
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            currLevel += 1
        return 0
    
    # балансировка после удаления
    def delete_fix(self, x):
        while x != self.root and x.red == False:
            if x == x.parent.left:
                s = x.parent.right
                if s.red == True:
                    s.red = 0
                    x.parent.red = True
                    self.rotate_left(x.parent)
                    s = x.parent.right

                if s.left.red == False and s.right.red == False:
                    s.red = True
                    x = x.parent
                else:
                    if s.right.red == False:
                        s.left.red = False
                        s.red = True
                        self.rotate_right(s)
                        s = x.parent.right

                    s.red = x.parent.red
                    x.parent.red = False
                    s.right.red = False
                    self.rotate_left(x.parent)
                    x = self.root
            else:
                s = x.parent.left
                if s.red == True:
                    s.red = False
                    x.parent.red = True
                    self.rotate_right(x.parent)
                    s = x.parent.left

                if s.right.red == False and s.right.red == False:
                    s.red = True
                    x = x.parent
                else:
                    if s.left.red == False:
                        s.right.red = False
                        s.red = True
                        self.rotate_left(s)
                        s = x.parent.left

                    s.red = x.parent.red
                    x.parent.red = False
                    s.left.red = False
                    self.rotate_right(x.parent)
                    x = self.root
        x.red = False

    def rb_transplant(self, u, v):
        if u.parent == None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent
    
    # поиск для левого удаления
    def minimum_left(self, node):
        while node.left != self.nil:
            node = node.left
        return node

    # поиск для правого удаления
    def minimum_right(self, node):
        while node.right != self.nil:
            node = node.right
        return node
    
    # удаление узла
    def delete(self, node, key):
        z = self.nil
        while node != self.nil:
            if node.val == key:
                z = node

            if node.val <= key:
                node = node.right
            else:
                node = node.left

        if z == self.nil:
            print("Cannot find key in the tree")
            return

        y = z
        y_original_red = y.red
        # нет левого ребенка -> правый ребенок на место удаленного
        if z.left == self.nil:
            x = z.right
            self.rb_transplant(z, z.right)
        # нет правого ребенка -> левый ребенок на место удаленного
        elif (z.right == self.nil):
            x = z.left
            self.rb_transplant(z, z.left)
        else:
            y = self.minimum_left(z.right)
            y_original_red = y.red
            x = y.right
            if y.parent == z:
               x.parent = y
            else:
                self.rb_transplant(y, y.right)
                y.right = z.right
                y.right.parent = y

            self.rb_transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.red = z.red
        if y_original_red == False:
            self.delete_fix(x)
 
    # поиск для левого удаления
    def MaxDepth(self, root):
        global max_node
        global max_d
        if root:
            if root.val!=0 and max_d< self.findDepth(self.root, root.val):
                max_node = root
                max_d = self.findDepth(self.root, root.val)
            self.MaxDepth(root.left)
            self.MaxDepth(root.right)
        return [max_node, max_d]

# задание вариант 19
def Task(tree):
    global max_node
    global max_d
    global max_height
    global max_height_node
    node_left, depth_left = tree.MaxDepth(tree.root.left)
    node = node_left
    while node!=tree.root:
        node = node.parent
        if max_height < tree.findHeightUtil(tree.root, node.val):
            max_height =tree.findHeightUtil(tree.root, node.val)
            max_height_node = node
        
    max_height_left = max_height
    max_height_node_left = max_height_node
    max_height = 0
    max_height_node = RedBlackNode(0)
    max_node = RedBlackNode(0)
    max_d = 0
    node_right, depth_right = tree.MaxDepth(tree.root.right)
    node = node_right
    while node!=tree.root:
        node = node.parent
        if max_height < tree.findHeightUtil(tree.root, node.val):
            max_height = tree.findHeightUtil(tree.root, node.val)
            max_height_node = node
        
    max_height_right = max_height
    max_height_node_right = max_height_node
    max_height_tree = tree.root
    tree.delete(tree.root, max_height_tree.val)
    print(tree)
    print('Длина максимального пути:',depth_left+depth_right+2)
    print('Максимальный путь из узла со значением', node_left.val, 'в узел со значением ', node_right.val )  
    print( 'Удален элемент со значением ', max_height_tree.val)
    print('Прямой обход дерева:')
    tree.pre_order(tree.root)
    print()
    
def get_nums(num):
    random.seed(1)
    nums = []
    for _ in range(num):
        nums.append(random.randint(1, num-1))
    return nums

import colorama
from colorama import Fore, Back
colorama.init()
tree = RedBlackTree()
for x in range(1, 10):
    tree.insert(x)
    #print(tree)
print('Начальное дерево')
print(tree)
while True:
    print('Выберите действие:')
    print('A) Добавить элемент')
    print('Б) Удалить элемент')
    print('В) Найти элемент')
    print('Г) Прямой обход дерева')
    print('Д) Обратный обход дерева')
    print('Е) Симметричный обход дерева')
    print('Ж) Определить глубину узла')
    print('З) Определить высоту узла')
    print('И) Определить уровень узла')
    print('К) Вывести дерево')
    print('TASK) Задание 2')
    print()
    print('X) Выйти')
    print()
    print()

    x = input()
    if x=='А':
      tree.insert(int(input("Введите число для добавления:")))
      print()
    elif x=='Б':
      tree.delete(tree.root, int(input("Введите число для удаления:")))
      print()
    elif x=='В':
        tree.find_element(tree.root, int(input("Введите число для поиска:")))
        print()
    elif x=='Г':
        tree.pre_order(tree.root)
        print()
    elif x=='Д':
        tree.post_order(tree.root)
        print()
    elif x=='Е':
        tree.in_order(tree.root)
        print()
    elif x=='Ж':
        print(tree.findDepth(tree.root, int(input("Введите число для определения глубины:"))))
        print()
    elif x=='З':
        print(tree.findHeightUtil(tree.root, int(input("Введите число для определения высоты:"))))
        print()
    elif x=='И':
        print(tree.Level(tree.root, int(input("Введите число для определения уровня:"))))
        print()
    elif x=='К':
      print(tree)
      print()
    elif x=='TASK':
      Task(tree)
      print()
    elif x=='Х':
        exit()
        print()
    else:
        print("Попробуйте снова")
        print()