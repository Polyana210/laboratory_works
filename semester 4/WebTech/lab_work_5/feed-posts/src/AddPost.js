import { useState } from 'react';

export default function AddPost({onAddPost}) {
  const [text, setText] = useState('');
  const [info, setInfo] = useState('');
  return (
    <>
     <p class="post_form">
      <h2>Новый пост</h2>
      <textarea value={text} id = "name_post" placeholder="Заголовок поста" onChange={(e) => setText(e.target.value)}>
        {text}
        
      </textarea>
      <textarea value={info} id = "info_post" placeholder="Текст" onChange={(e) => setInfo(e.target.value)}>
        {info}
      </textarea>

      <button
        class = "but"
        onClick={() => {
          setText('');
          setInfo('');
          onAddPost(text, info);
        }}>
        Добавить
      </button>
      </p>
   

      
    </>

    
  );
}
