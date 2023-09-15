import React, { useState, useEffect } from "react"
import { httpHelper } from "../httpHelper"

const DropCompanies = ({ establishmentsId, handleValue }) => {
	const [establishments, setEstablishments] = useState([])
	const [establishment, setEstablishment] = useState(establishmentsId)

	const url = "http://localhost:5000/establishments"
	const api = httpHelper()

	useEffect(() => {
		api
			.get(url)
			.then(res => {
				setEstablishments([{ id: 0, name: "Выберите УО" }, ...res])
			})
			.catch(err => console.log(err))
	}, [])

	return (
		<p><label><b>Название учебного заведения:</b><select
			name='establishmentsId'
			value={establishment}
			onChange={e => {
				setEstablishment(e.target.value)
				handleValue(e)
			}}
		>
			{establishments.map(c => (
				<option value={c.id} key={c.id}>
					{c.name}
				</option>
			))}
		</select></label></p>
    
	)
}

export default DropCompanies
