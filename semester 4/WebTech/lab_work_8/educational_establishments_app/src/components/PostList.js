import React from 'react';
import PostItem from './PostItem';
import { useSelector } from "react-redux";

const TodoList = () => {
	const todos = useSelector((state)=>{
		return state.tasks;
	});

	return (
		<ul className="tasks-list">
			{todos.map((todo) => (
				<PostItem id={todo.id} req = {todo.req} name={todo.name} info={todo.info} specialities = {todo.specialities}/>
			))}
		</ul>
	);
};

export default TodoList;
