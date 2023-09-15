import React, { useState } from "react"
import DropEstablishment from "./DropEstablishments"
import DropSubjects from "./DropSubjects"
const FormFilter = ({ subjData = {}, postSpeciality }) => {
	const [subj, setSubj] = useState({
		name:subjData.name ?? "",
		info: subjData.info ?? "",
	})

	const handleValue = e => {
		setSubj({ ...subj, [e.target.name]: e.target.value })
	}

	
	const submitSubj = e => {
		e.preventDefault()
		postSpeciality(subj)
	}

	return (
		<form onSubmit={submitSubj} className='row'>
			<input
				type='text'
				name='name'
				value={subj.name}
				placeholder='Name'
				onChange={e => handleValue(e)}
			/>
			<input
				type='text'
				name='info'
				value={subj.info}
				placeholder='Information'
				onChange={e => handleValue(e)}
			/>
      <DropSubjects subject_1_id={subj.subject_1} subject_2_id={subj.subject_2} subject_3_id={subj.subject_3} handleValue={handleValue} />
			<input
				className='btn-submit'
				type='submit'
				value={"Save user"}
			/>


		</form>
	)
}

export default FormFilter