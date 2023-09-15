import React, { useState } from "react"

const FormAddRequest = ({ requestData = {}, postRequest}) => {
	const [request, setRequest] = useState({
		name: requestData.name ?? "",
    city: requestData.city ?? "",
		phone: requestData.phone ?? "",
    info: requestData.info ?? "",
    comments: requestData.comments ?? []
	})

	const handleValue = e => {
		setRequest({ ...request, [e.target.name]: e.target.value })
	}

	const submitRequest = e => {
		e.preventDefault()
		postRequest(request)
	}

	return (
    <div className="add_reqq">
		<form onSubmit={submitRequest} >
			<p><label><b>Название учебного заведения:</b>
      <input  className="input_12"
      	type='text'
				name='name'
				value={request.name}
				placeholder='Name'
				onChange={e => handleValue(e)}
			/></label>
      </p>
      <p><label><b>Город:</b>
			<input  className="input_12"
				type='text'
				name='city'
				value={request.city}
				placeholder='City'
				onChange={e => handleValue(e)}
			/></label></p>
      <p><label><b>Телефон:</b>
			<input  className="input_12"
				type='tel'
				name='phone'
				value={request.phone}
				placeholder='Phone (10)'
				pattern='[0-9]{10}'
				onChange={e => handleValue(e)}
			/></label></p>
      <p><label><b>Дополнительная информация:</b>
      <input className="input_12"
				type='text'
				name='info'
				value={request.info}
				placeholder='Information'
				onChange={e => handleValue(e)}
			/></label></p>
      <p>
      <p className="but_1">
			<input
				className='input_123'
				type='submit'
				value={"Сохранить запрос"}        
			/>
      </p></p>
      
		</form>
    </div>
	)
}

export default FormAddRequest
