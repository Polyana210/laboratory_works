import { useState } from 'react';
import AddPost from './AddPost.js';
import PostsList from './PostsList.js';
import Post from './Post.js';
import { Routes, Route, Link } from "react-router-dom"

export default function PostApp() {
  const [posts, setPosts ] = useState(initialTasks);
  function handleAddPost(text, info) {
    let now = new Date();
    let date1= now.toLocaleDateString("ru-RU");
    setPosts([
      ...posts,
      {
        id: nextId++,
        text: text,
        info: info,
        date: date1
      },
    ]);
  }

  function handleDeletePost(taskId) {
    setPosts(posts.filter((t) => t.id !== taskId));
  }

  return (
    <div className="App">
      <nav class = "navig">
        <ul>
          <Link to="/"><button class = "but">Все посты</button></Link>
         
          <Link to="add"><button class = "but">Новый пост</button></Link>
          
        </ul>
      </nav>
      <div className="main">
        {/* Define all the routes */}
        <Routes>
          <Route path="/" element={<PostsList posts={posts} onDeletePost={handleDeletePost}/>}></Route>
          <Route path="add" element={<AddPost onAddPost={handleAddPost} />}></Route>
          <Route path="post/:id" element={<Post posts={posts}/>}/>
        </Routes>
      </div>
    </div>
  )
}

export const NotFound = () => {
  return <div>This is a 404 page</div>
}


 
let nextId = 3;
const initialTasks = [
  {id: 0, text: '​5 самых интересных фактов о слонах', info: '1.Слоны — ближайшие родственники ныне вымерших мамонтов.\n2. На сегодняшний день насчитывается три вида этих уникальных животных: индийский слон, африканский саванный и африканский лесной. Ранее их было 40 видов.\n3. Африканский слон признан самым крупным млекопитающим, которое обитает на Земле.\n4.Самый большой слон, когда-либо известный, был самец африканского слона, убитый на территории Анголы в 1974 году, весом около 12240 килограммов.\n5.Средняя масса тела этих животных — около 5 тонн, а длина туловища — 6-7 метров.', date: '04.03.2021'},
  {id: 1, text: 'Как происходит написание статей?',  info: 'В идеале автор полностью пишет текст «из головы», основываясь на собственных знаниях и опыте. Однако так происходит далеко не всегда. Существует такое понятие, как рерайтинг. При этом райтер берет какую-то определенную статью из интернета и пересказывает ее своими словами, подбирает синонимы, меняет местами предложения. Такой текст технически получится уникальным, но пользы читателям от него будет немного, ведь содержание статьи полностью повторяет текст, который уже был где-то опубликован.', date:"13.01.2022"},
  {id: 2, text: 'Творожные сырники по ГОСТу',  info:'Соедините творог, яйцо и сахар. Масса должна быть однородной консистенции. Всыпьте в неё муку, тщательно перемешайте и начинайте жарить.', date:'15.11.2022'},
];