import { useState } from 'react';

export default function TaskList({tasks, onChangeTask, onDeleteTask}) {
  return (
    <ul>
      {tasks.map((task) => (
        <li key={task.id}>
          <Task task={task} onChange={onChangeTask} onDelete={onDeleteTask} />
        </li>
      ))}
    </ul>
  );
}

function Task({task, onChange, onDelete}) {
  const [isEditing, setIsEditing] = useState(false);
  let taskContent;
 
  if (isEditing) {
    taskContent = (
      <><span>
        <input
         class = "task_name"
          value={task.text}
          onChange={(e) => {
            onChange({
              ...task,
              text: e.target.value,
            });
            
          }}
        />
        </span>
        <span >
        <input class= "edit_task"
        required
        type="number"
        step="any"
          value={task.price}
          onChange={(e) => {
            onChange({
              ...task,
              price: e.target.value,
            });
          }}
        />
       </span>
       <span>
        <input
        class= "edit_task"
        required
        type="number"
        step="any"
          value={task.count}
          onChange={(e) => {
            onChange({
              ...task,
              count: e.target.value,
            });
          }}
        />
        </span>
        <button class = "but" onClick={() => setIsEditing(false)}>Сохранить</button>
        <button class = "but" onClick={() => onDelete(task.id)}>Удалить</button>
      </>
    );
  } else {
    if (task.text && task.price && task.count)
    taskContent = (
      <>
        
        <span class ="task_name">{task.text}</span>
        <span class= "edit_task">{task.price}</span>
        <span class= "edit_task">{task.count}</span>
      
        <button class = "but" onClick={() => setIsEditing(true)}>Изменить</button>
        <button class = "but" onClick={() => onDelete(task.id)}>Удалить</button>
      </>
    );
    else taskContent = (
      <><span>
        <input
         class = "task_name"
          value={task.text}
          onChange={(e) => {
            onChange({
              ...task,
              text: e.target.value,
            });
            
          }}
        />
        </span>
        <span >
        <input class= "edit_task"
        required
        type="number"
        step="any"
          value={task.price}
          onChange={(e) => {
            onChange({
              ...task,
              price: e.target.value,
            });
          }}
        />
       </span>
       <span>
        <input
        class= "edit_task"
        required
        type="number"
        step="any"
          value={task.count}
          onChange={(e) => {
            onChange({
              ...task,
              count: e.target.value,
            });
          }}
        />
        </span>
        <button class = "but" onClick={() => setIsEditing(false)}>Сохранить</button>
        <button class = "but" onClick={() => onDelete(task.id)}>Удалить</button>
      </>
    );
  }
  return (
    <label>
      {taskContent}      
    </label>
  );
}
