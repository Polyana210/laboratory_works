import React from "react";
import {useState} from 'react';
const TableEstablishments = ({ establishments}) => {


	const Row = ({ establishment }) => {
    const [comment, setComment] = useState('');
		return (
			  <>
        
        <div className="info_establ">
          
					<p><b>Название УО: </b>{establishment.name}</p>
          <p><b>Город: </b>{establishment.city}</p>
					<p><b>Информация: </b>{establishment.info}</p>
          <p><b>Отзывы: </b>{(establishment.comments).toString()}</p>
          <input class="input_11"
                type="text"
                value={comment}
                onChange={(e) => setComment(e.target.value)}
                placeholder="Напишите отзыв"
            />

            <button class="but_form"
                onClick={() =>{(establishment.comments).push(comment); setComment("")}}
            >
                Отправить
            </button>
          </div>
			</>
		)
	}
  
	return (
    
			
			<div className='rows'>
				{establishments.map(u => <Row establishment={u} key={u.id} />)}
			</div>
	)
}

export default TableEstablishments
