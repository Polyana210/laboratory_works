import React from "react";
import Form from "./FormAddSpeciality";
const TableSpecialities = ({ specialities, postSpeciality, deleteSpeciality,  num1, num2, num3}) => {
	

	const Row = ({ speciality }) => {

    let fl1 =false
    let fl2 = false
    let fl3 = false
    console.log(speciality.subject_1_id == num1 || speciality.subject_3_id == num1 || speciality.subject_2_id == num1)
    if (speciality.subject_1_id == num1 || speciality.subject_3_id == num1 || speciality.subject_2_id == num1){ fl1 = true}
    if (speciality.subject_1_id == num2 || speciality.subject_3_id == num2 || speciality.subject_2_id == num2){ fl2 = true}
    if (speciality.subject_1_id == num3 || speciality.subject_3_id == num3 || speciality.subject_2_id == num3){ fl3 = true}
    if (fl1&&fl2&&fl3)
    return (
			  <>
        
          <div className="spec">
					<p><b>Название специальности: </b>{speciality.name}</p>
					<p><b>Квалификация: </b>{speciality.info}</p>
          </div>
			</>
		)
	}
  
	return (
		<div className='speciality_panel'>
			<h2>Специальности для Вас:</h2>
			<div className='rows'>
				{specialities.map(u => <Row speciality={u} key={u.id} />)}
			</div>
		</div>
	)
}

export default TableSpecialities
