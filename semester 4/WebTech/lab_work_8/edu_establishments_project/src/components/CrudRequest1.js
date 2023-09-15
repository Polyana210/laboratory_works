import React, { useState, useEffect } from "react"
import Form from "./FormAddRequest"

import { httpHelper } from "../httpHelper"

const CrudRequest = () => {
	const [requests, setRequests] = useState([])
  const [establishments, setEstablishments] = useState([])
	const url = "http://localhost:5000/requests"
	const api = httpHelper()
  const url1 = "http://localhost:5000/establishments"
	useEffect(() => {
		getRequests()
	}, [])

	const postRequest = request => {
		api
			.post(`${url}`, { body: request })
			.then(res => getRequests())
			.catch(err => console.log(err))
	}

	const updateRequest = (id, request) => {
		api
			.put(`${url}/${id}`, { body: request })
			.then(res => getRequests())
			.catch(err => console.log(err))
	}

  const agreeRequest = (id, request) => {	
    api
    .post(`${url1}`, { body: request })
    .then(res => getEstablishments())
    .catch(err => console.log(err))
    
	}

  const getEstablishments = () => {
		api
			.get(`${url1}`)
			.then(res => {
				setEstablishments(res)
			})
			.catch(err => console.log(err))
	}

	const deleteRequest = id => {
		api
			.del(`${url}/${id}`, {})
			.then(res => getRequests())
			.catch(err => console.log(err))
	}

	const getRequests = () => {
		api
			.get(`${url}`)
			.then(res => {
				setRequests(res)
			})
			.catch(err => console.log(err))
	}

  
	return (
		
			<Form postRequest={postRequest}  agreeRequest = {agreeRequest}/>
			
	)
  
}

export default CrudRequest
