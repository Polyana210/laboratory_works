import { useState } from 'react';
import AddTask from './AddTask.js';
import TaskList from './TaskList.js';

export default function TaskApp() {
  const [tasks, setTasks] = useState(initialTasks);

  function handleAddTask(text, price, count) {
    if (text && price && count)
    setTasks([
      ...tasks,
      {
        id: nextId++,
        text: text,
        price: price,
        count: count,
      },
    ]);
  }

  function handleChangeTask(task) {
    setTasks(
      tasks.map((t) => {
        if (t.id === task.id) {
          return task;
        } else {
          return t;
        }
      })
    );
  }

  function handleDeleteTask(taskId) {
    setTasks(tasks.filter((t) => t.id !== taskId));
  }

  function calc_sum(){
    let c_sum=0;
    for (let i in tasks){
      c_sum+=tasks[i].count*tasks[i].price;
    }
    return c_sum.toFixed(2);
  }

  return (
    <>
      <h1>КАЛЬКУЛЯТОР ПРОДУКТОВ</h1>
      <AddTask onAddTask={handleAddTask} />
      <TaskList
        tasks={tasks}
        onChangeTask={handleChangeTask}
        onDeleteTask={handleDeleteTask}
      />
      <h2>СУММАРНАЯ СТОИМОСТЬ:  {calc_sum()} руб.</h2>
      
    </>
  );
}
 
let nextId = 3;
const initialTasks = [
  {id: 0, text: 'Молоко', price:'1.9', count:'3'},
  {id: 1, text: 'Яблоки',  price:'6.9', count:'1.73'},
  {id: 2, text: 'Морковь',  price:'1.59', count:'0.7'},
];
