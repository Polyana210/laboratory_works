import React, { useState } from 'react';
import { useDispatch } from "react-redux";
import { addEstablishment } from "../redux/postsSlice";

const AddEstablishment = () => {

  const [name, setName] = useState('');
  const [info, setInfo] = useState('');
	const dispatch = useDispatch();

	const onSubmit = (event) => {
		event.preventDefault();

		if(name.trim().length === 0 || info.trim().length === 0)
		{
			alert("Нужно заполнить все поля !!");
			setName("");
      setInfo("");
			return;
		}

		dispatch(
			addEstablishment({
				name: name,
        info: info
			})
		);

		setName("");
    setInfo("");
	};

	return (
		      
    <>
     <p class="post_form">
      <h2>Новое учебное заведение</h2>
      <textarea value={name} id = "name_post" placeholder="Заголовок поста" onChange={(e) => setName(e.target.value)}>
        {name}
        
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

export default AddEstablishment;
