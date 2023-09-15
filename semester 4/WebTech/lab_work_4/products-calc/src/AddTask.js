import { useState } from 'react';

export default function AddTask({onAddTask}) {
  const [text, setText] = useState('');
  const [price, setPrice] = useState('');
  const [count, setCount] = useState('');
  return (
    <>
      <input
        class = "task_name_1"
        placeholder="Название"
        value={text}
        onChange={(e) => setText(e.target.value)}
        required
      />
      
      
      <input
        class = "edit_task"
        placeholder="Цена"
        value={price}
        onChange={(e) => setPrice(e.target.value)}
        pattern="^[0-9]+$"
        required
        min = '0.01'
        type="number"
        step="any"
      />

      <input 
        class = "edit_task"
        placeholder="Количество"
        value={count}
        onChange={(e) => setCount(e.target.value)}
        pattern="^[0-9]+$"
        min = '0.01'
        required
        type="number"
      />
      <button
        class = "but"
        onClick={() => {
          setText('');
          setPrice('');
          setCount('');
          onAddTask(text, price, count);
        }}>
        Добавить
      </button>
    </>

    
  );
}
