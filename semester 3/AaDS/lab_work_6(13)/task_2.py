# Задание 2. Пользователь вводит представление графа в одном виде, необходимо вывести его в другом виде.
# Список смежности -> матрица инцидентности.

def incidence_matrix(vertex, edges, adjacency_list):
    inc_matrix = []
    for i in range(vertex):
      inc_matrix.append([])
      for k in range(edges):
        inc_matrix[i].append(" 0")
    l=0
    for i in range(0, len(adjacency_list)):
      for k in adjacency_list[i]:
        if i==k-1:
          inc_matrix[i][l]=" 2"
        else:
          inc_matrix[i][l]=" 1"
          inc_matrix[k-1][l]="-1"
        l+=1

    print("Incidence_matrix:") 
    for i in range(vertex):
        print(*inc_matrix[i])

vertex = int(input("Enter the number of vertices: "))
adjacency_list=[]

k=0
edges = 0
for i in range(vertex):
  adjacency_list.append([int(i) for i in input('Enter adjacency list').split()])
  edges+=len(adjacency_list[i])
  k+=1
print(adjacency_list)
print(edges)
incidence_matrix(vertex, edges, adjacency_list)