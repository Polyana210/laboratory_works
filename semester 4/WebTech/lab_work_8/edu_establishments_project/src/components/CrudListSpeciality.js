import React, { useState, useEffect } from "react"
import Table from "./TableSpeciality"
import DropSubjects from "./DropSubjects"

import { httpHelper } from "../httpHelper"

const CrudListSpeciality = ({num1, num2, num3}) => {
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

	const submitSpeciality = e => {
		e.preventDefault()
	}
 
  let ss1=num1, ss2=num2, ss3=num3;

  return (
  <Table
  specialities={specialities}
  setSpecialities={setSpecialities}
  postSpeciality={postSpeciality}
  deleteSpeciality={deleteSpeciality}
  num1 = {ss1}
  num2 = {ss2}
  num3 = {ss3}
/>
  )
}

export default CrudListSpeciality
