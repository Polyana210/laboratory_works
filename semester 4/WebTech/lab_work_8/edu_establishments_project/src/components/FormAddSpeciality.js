import React, { useState } from "react"
import DropEstablishment from "./DropEstablishments"
import DropSubjects from "./DropSubjects"
const FormAddSpeciality = ({ specialityData = {}, postSpeciality }) => {
	const [speciality, setSpeciality] = useState({
		name:specialityData.name ?? "",
		info: specialityData.info ?? "",
	})

	const handleValue = e => {
		setSpeciality({ ...speciality, [e.target.name]: e.target.value })
	}

	
	const submitSpeciality = e => {
		e.preventDefault()
		postSpeciality(speciality)
	}

	return (
    <div className="add_reqq">
		<form onSubmit={submitSpeciality}>
    <p><label><b>Название специальности:</b><input
				type='text'
				name='name'
				value={speciality.name}
				placeholder='Name'
				onChange={e => handleValue(e)}
			/></label></p>
			<p><label><b>Квалификация:</b><input
				type='text'
				name='info'
				value={speciality.info}
				placeholder='Information'
				onChange={e => handleValue(e)}
			/></label></p>
      <DropEstablishment establishmentsId={speciality.establ} handleValue={handleValue} />
      <DropSubjects subject_1_id={speciality.subject_1} subject_2_id={speciality.subject_2} subject_3_id={speciality.subject_3} handleValue={handleValue} />
      <p className="but_1">
			<input
				className='input_123'
				type='submit'
				value={"Сохранить"}
			/></p>


		</form>
    </div>
	)
}

export default FormAddSpeciality
