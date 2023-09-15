import React, { useState, useEffect } from "react"
import Table from "./TableEstablishments"

import { httpHelper } from "../httpHelper"

const CrudListEstablishments = () => {
	const [establishments, setEstablishments] = useState([])
	const url = "http://localhost:5000/establishments"
	const api = httpHelper()
	useEffect(() => {
		getEstablishments()
	}, [])

	
	const getEstablishments = () => {
		api
			.get(`${url}`)
			.then(res => {
				setEstablishments(res)
			})
			.catch(err => console.log(err))
	}
 
  return (
		<>
				<Table
					establishments={establishments}
				/>
		</>
	)
}

export default CrudListEstablishments