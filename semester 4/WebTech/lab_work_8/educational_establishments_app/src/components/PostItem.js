import React from 'react';
import { useDispatch } from "react-redux";
import { deletePost } from "../redux/postsSlice";
import { useNavigate } from "react-router-dom";

const TodoItem = ({ id, req, name, info, specialities}) => {

	const dispatch = useDispatch();

	const removeTask=()=>{
		dispatch(
			deletePost({
				id: id
			})
		)
	}
   
  let navigate = useNavigate(); 
  const routeChange = () =>{ 
    let path = "post/:"+id;
    navigate(path);
  }
  let postContent;
  if (req===false){


   let spec = 'Специальности: \n'
   for (let i in specialities){
    spec+= specialities[i]+'\n'
   }
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_1" onDoubleClick={() => routeChange(id)}>   
      <h2> {name}</h2>
      <h5>{info} </h5>     

      <textarea id = "info_post" disabled>
      {spec}
      </textarea>
      <button class = "but" onClick={()=>{routeChange(id);}}>Подробнее</button>
      <button class = "but" onClick={()=>{routeChange(id);}}>Отзывы</button>
      </p>  
      
   </>
    );}
    else postContent=(<></>);
	return (
		<label>
      {postContent}
    </label>    
	);
};

export default TodoItem;
