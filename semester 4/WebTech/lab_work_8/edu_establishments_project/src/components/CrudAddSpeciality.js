import React, { useState, useEffect } from "react"
import Form from "./FormAddSpeciality"
import { httpHelper } from "../httpHelper"

const CrudAddSpeciality = () => {
	const [specialities, setSpecialities] = useState([])
	const url = "http://localhost:5000/specialities"
	const api = httpHelper()
	useEffect(() => {
		getSpecialities()
	}, [])

	const postSpeciality = speciality => {
		api
			.post(`${url}`, { body: speciality })
			.then(res => getSpecialities())
			.catch(err => console.log(err))
	}

	const updateSpeciality = (id, request) => {
		api
			.put(`${url}/${id}`, { body: request })
			.then(res => getSpecialities())
			.catch(err => console.log(err))
	}

  const deleteSpeciality = id => {
		api
			.del(`${url}/${id}`, {})
			.then(res => getSpecialities())
			.catch(err => console.log(err))
	}

	const getSpecialities = () => {
		api
			.get(`${url}`)
			.then(res => {
				setSpecialities(res)
			})
			.catch(err => console.log(err))
	}
 
  return (
		<>
			<h1>Добавить специальность</h1>
			<Form postSpeciality={postSpeciality}/>
			
		</>
	)
}

export default CrudAddSpeciality
