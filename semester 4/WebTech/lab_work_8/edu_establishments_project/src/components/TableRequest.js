import React from "react"
import Form from "./FormAddRequest"

const TableRequests = ({ requests, postRequest, agreeRequest, deleteRequest }) => {
	

	const Row = ({ request }) => {
		return (
			  <>
          <div className="info_establ">
        
          
					<p><b>Название УО: </b>{request.name}</p>
					<p><b>Город: </b>{request.city}</p>
					<p><b>Контактный телефон: </b>{request.phone}</p>
					<p><b>Дополнительная информация: </b>{request.info}</p>
          
					<div className='buttons'>
						<button className='del' onClick={() => deleteRequest(request.id)}>Отклонить</button>
            <button className='agree' onClick={() => agreeRequest(request.id, request)}>Принять</button>
					</div>
				</div>
			</>
		)
	}
  
	return (
			
			<div className='rows'>
				{requests.map(u => <Row request={u} key={u.id} />)}
			</div>
	)
}

export default TableRequests
