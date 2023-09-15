import React from 'react';
import AddPost from './components/AddPost';
import PostList from './components/PostList';
import Post from './components/Post.js';
import { Routes, Route, Link } from "react-router-dom"
import { useSelector } from "react-redux";

const App = () => {
  const todos = useSelector((state)=>{
		return state.tasks;
	});

	return (
    
		<div className="app">
      <nav class = "navig">
        <ul>
          <Link to="/"><button class = "but">Все посты</button></Link>
         
          <Link to="add"><button class = "but">Новый пост</button></Link>
          
        </ul>
      </nav>
      <Routes>
          <Route path="/" element={<PostList />}></Route>
          <Route path="add" element={<AddPost />}></Route>
          <Route path="post/:id" element={<Post posts={todos}/>}/>
        </Routes>
		</div>
	);
};

export default App;
