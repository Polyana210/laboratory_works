import { useState } from 'react';
import { useNavigate } from "react-router-dom";

export default function PostsList({posts, onDeletePost}) {
  return (
    <ul>
      {posts.map((post) => (
        <li key={post.id}>
          <Post post={post} onDelete={onDeletePost} />
        </li>
      ))}
    </ul>
  );
}

function Post({post, onDelete}) {
  let postContent;
  let navigate = useNavigate(); 
  const routeChange = () =>{ 
    let path = "post/:"+post.id; 
    navigate(path);
  }
    if (post.text && post.info)
    if(post.id%4===0)
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_1"  onDoubleClick={() => routeChange(post.id)}>   
      <h2>Пост номер {post.id+1} ({post.date})</h2>
      <textarea id = "name_post" disabled>
        {post.text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {post.info}
      </textarea>
      <button class = "but" onClick={() => onDelete(post.id)}>Удалить</button>
      <button class = "but" onClick={() => routeChange(post.id)}>Открыть</button>
      </p>  
      
   </>
    );
    else if (post.id%4===1)
    postContent = (
      
      <>    
      <p class="post_form_1" id="post_form_2"  onDoubleClick={() => routeChange(post.id)}>   
      <h2>Пост номер {post.id+1} ({post.date})</h2>
      <textarea id = "name_post" disabled>
        {post.text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {post.info}
      </textarea>
      <button class = "but" onClick={() => onDelete(post.id)}>Удалить</button>
      <button class = "but" onClick={() => routeChange(post.id)}>Открыть</button>
      </p>  
      
   </>
    );
    else if (post.id%4===2)
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_3"  onDoubleClick={() => routeChange(post.id)}>   
      <h2>Пост номер {post.id+1} ({post.date})</h2>
      <textarea id = "name_post" disabled>
        {post.text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {post.info}
      </textarea>
      <button class = "but" onClick={() => onDelete(post.id)}>Удалить</button>
      <button class = "but" onClick={() => routeChange(post.id)}>Открыть</button>
      </p>  
      
   </>
    );
    else 
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_4"  onDoubleClick={() => routeChange(post.id)}>   
      <h2>Пост номер {post.id+1} ({post.date})</h2>
      <textarea id = "name_post" disabled>
        {post.text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {post.info}
      </textarea>
      <button class = "but" onClick={() => onDelete(post.id)}>Удалить</button>
      <button class = "but" onClick={() => routeChange(post.id)}>Открыть</button>
      </p>  
      
   </>
    );
  return (
   <label>
      {postContent}
      
    </label>
  );
}
