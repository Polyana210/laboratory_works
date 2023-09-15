import { useParams } from 'react-router-dom'

export default function Post({posts}){

    let params = useParams();
    let index = parseInt(params.id.slice(1)) ;
    
    if( index <= posts.length){
        let post = posts.find(element => element.id === index);
        return(
            <>
            <div>
          <PostItem post = {post}/>
            </div>
        </>    
        );
    }else{
        return <h1>404 - Страница не найдена</h1>;
    }
}


function PostItem({ post }) {
  let postContent;
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
    </p>  
    
 </>
  );
  else 
  postContent = (
    
    <>   
    <p class="post_form_1" id="post_form_4" >   
    <h2>Пост номер {post.id+1} ({post.date})</h2>
    <textarea id = "name_post" disabled>
      {post.text}
      
    </textarea>

    <textarea id = "info_post" disabled>
      {post.info}
    </textarea>
    </p>  
    
 </>
  );

    return (
      
   <label>
   {postContent}
   
 </label>
    );
  }

