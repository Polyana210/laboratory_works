import React from 'react';
import { useDispatch } from "react-redux";
import { deletePost } from "../redux/postsSlice";
import { useNavigate } from "react-router-dom";

const TodoItem = ({ id, text, info, date }) => {

	const dispatch = useDispatch();

	const removeTask=()=>{
		dispatch(
			deletePost({
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
  
    if(id%4===0)
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_1" onDoubleClick={() => routeChange(id)}>   
      <h2>Пост номер {id+1} ({date})</h2>
      <textarea id = "name_post" disabled>
        {text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {info}
      </textarea>
      <button class = "but" onClick={()=>{removeTask();}}>Удалить</button>
      <button class = "but" onClick={()=>{routeChange(id);}}>Открыть</button>
      </p>  
      
   </>
    );
    else if (id%4===1)
    postContent = (
      
      <>    
      <p class="post_form_1" id="post_form_2" onDoubleClick={() => routeChange(id)}>   
      <h2>Пост номер {id+1} ({date})</h2>
      <textarea id = "name_post" disabled>
        {text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {info}
      </textarea>
      <button class = "but" onClick={()=>{removeTask();}}>Удалить</button>
      <button class = "but" onClick={()=>{routeChange(id);}}>Открыть</button>
      </p> 
      
   </>
    );
    else if (id%4===2)
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_3" onDoubleClick={() => routeChange(id)}>   
      <h2>Пост номер {id+1} ({date})</h2>
      <textarea id = "name_post" disabled>
        {text}
        
      </textarea>

      <textarea id = "info_post" disabled >
        {info}
      </textarea>
      <button class = "but" onClick={()=>{removeTask();}}>Удалить</button>
      <button class = "but" onClick={()=>{routeChange(id);}}>Открыть</button>
      </p>  
      
   </>
    );
    else 
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_4" onDoubleClick={() => routeChange(id)}>   
      <h2>Пост номер {id+1} ({date})</h2>
      <textarea id = "name_post" disabled>
        {text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {info}
      </textarea>
      <button class = "but" onClick={()=>{removeTask();}}>Удалить</button>
      <button class = "but" onClick={()=>{routeChange(id);}}>Открыть</button>
      </p>  
      
   </>
    )
	return (
		<label>
      {postContent}
    </label>

    
	);
};

export default TodoItem;
