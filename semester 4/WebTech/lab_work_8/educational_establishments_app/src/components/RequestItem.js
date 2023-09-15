import React from 'react';
import { useDispatch } from "react-redux";
import { deletePost, agreePost} from "../redux/postsSlice";
import { useNavigate } from "react-router-dom";
import { useState } from 'react';
const TodoItem = ({ id, req,  name, info, specialities, task}) => {

	const dispatch = useDispatch();

	const removeTask=()=>{
		dispatch(
			deletePost({
				id: id
			})
		)
	}

  const agreeTask=()=>{
		dispatch(
			agreePost({
				id: id
			})
		)
	}

 
  let postContent;
  let navigate = useNavigate(); 
  const routeChange = () =>{ 
    let path = "post/:"+id;
    navigate(path);
  }

  const agree = () =>{
    req=false
  }
   if (req){
   let spec = 'Специальности: \n'
   for (let i in specialities){
    spec+= specialities[i]+'\n'
   }
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_1" >   
      <h2> {name}</h2>

      <textarea id = "info_post" disabled>
      {info}
      </textarea>
      <button class = "but" onClick={()=>{agreeTask()}}>Принять</button>
      <button class = "but" onClick={()=>{removeTask();}}>Отклонить</button>
      </p>  
      
   </>
    );
	return (
		<label>
      {postContent}
    </label>

    
	);}
  else return <></>
};

export default TodoItem;
