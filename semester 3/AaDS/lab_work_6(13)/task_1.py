# Задание 1. Пользователь вводит список вершин и список ребер графа. Вывести на экран для заданного графа:
# матрицу смежности
# матрицу инцидентности.

def adjacency_matrix(vertex, edges):
    adj_matrix = []
    for i in range(vertex):
      adj_matrix.append([])
      for k in range(vertex):
        adj_matrix[i].append(0)

    for i in range(0, len(edges), 2):
      adj_matrix[edges[i]-1][edges[i+1]-1]=1

    print("Adjacency_matrix:")
    for i in range(vertex):
        print(*adj_matrix[i])


def incidence_matrix(vertex, edges):
    inc_matrix = []
    for i in range(vertex):
      inc_matrix.append([])
      for k in range(len(edges)//2):
        inc_matrix[i].append(" 0")

    l=0
    for i in range(0, len(edges), 2):
        if edges[i]==edges[i+1]:
          inc_matrix[edges[i]-1][l]=2
        else:
          inc_matrix[edges[i]-1][l]=" 1"
          inc_matrix[edges[i+1]-1][l]='-1'
        l+=1
    print("Incidence_matrix:")
    for i in range(vertex):
        print(*inc_matrix[i])


vertex = int(input("Enter the number of vertices: "))
edges = [int(i) for i in input("Enter a list of graph edges ").split()]
if len(edges)%2!=0:
  print("Error")
  exit()
for i in edges:
  if i>vertex:
    print("Error 1")
    exit()
print()
adjacency_matrix(vertex, edges)
print()
incidence_matrix(vertex, edges)