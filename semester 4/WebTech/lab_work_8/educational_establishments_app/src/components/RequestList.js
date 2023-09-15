import React from 'react';
import RequestItem from './RequestItem';
import { useSelector } from "react-redux";

const TodoList = () => {
	const requests = useSelector((state)=>{
		return state.tasks;
	});

	return (
		<ul className="tasks-list">
			{requests.map((todo) => (
				<RequestItem id={todo.id} req={todo.req} name={todo.name} info={todo.info} specialities = {todo.specialities} task={todo}/>
			))}
		</ul>
	);
};

export default TodoList;