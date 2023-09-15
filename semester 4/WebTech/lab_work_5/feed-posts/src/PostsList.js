import { useState } from 'react';

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
    if (post.text && post.info)
    if(post.id%4===0)
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_1">   
      <h2>Пост номер {post.id+1} ({post.date})</h2>
      <textarea id = "name_post" disabled>
        {post.text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {post.info}
      </textarea>
      <button class = "but" onClick={() => onDelete(post.id)}>Удалить</button>
      </p>  
      
   </>
    );
    else if (post.id%4===1)
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_2">   
      <h2>Пост номер {post.id+1} ({post.date})</h2>
      <textarea id = "name_post" disabled>
        {post.text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {post.info}
      </textarea>
      <button class = "but" onClick={() => onDelete(post.id)}>Удалить</button>
      </p>  
      
   </>
    );
    else if (post.id%4===2)
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_3">   
      <h2>Пост номер {post.id+1} ({post.date})</h2>
      <textarea id = "name_post" disabled>
        {post.text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {post.info}
      </textarea>
      <button class = "but" onClick={() => onDelete(post.id)}>Удалить</button>
      </p>  
      
   </>
    );
    else 
    postContent = (
      
      <>   
      <p class="post_form_1" id="post_form_4">   
      <h2>Пост номер {post.id+1} ({post.date})</h2>
      <textarea id = "name_post" disabled>
        {post.text}
        
      </textarea>

      <textarea id = "info_post" disabled>
        {post.info}
      </textarea>
      <button class = "but" onClick={() => onDelete(post.id)}>Удалить</button>
      </p>  
      
   </>
    );
  if (post.id%4===0)return (
   <label>
      {postContent}
      
    </label>
    
  );

  else if (post.id%4===1)return (
    <label>
      {postContent}
    </label>
    
  );
  else if (post.id%4===2)return (
    <label>
      {postContent}
      
    </label>
    
  );
  else return (
    <label>
      
      {postContent}
      
    </label>
 );
}
