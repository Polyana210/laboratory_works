import React, { useState } from 'react';
import { useDispatch } from "react-redux";
import { addPost } from "../redux/postsSlice";

const AddPost = () => {

  const [text, setText] = useState('');
  const [info, setInfo] = useState('');
  let now = new Date();
  let date1= now.toLocaleDateString("ru-RU");
	const dispatch = useDispatch();

	const onSubmit = (event) => {
		event.preventDefault();

		if(text.trim().length === 0 || info.trim().length === 0)
		{
			alert("Нужно заполнить все поля !!");
			setText("");
      setInfo("");
			return;
		}

		dispatch(
			addPost({
				text: text,
        info: info,
        date: date1
			})
		);

		setText("");
    setInfo("");
	};

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
        onClick={onSubmit}>
        Добавить
      </button>
      </p>
   

      
    </>
	);
};

export default AddPost;
