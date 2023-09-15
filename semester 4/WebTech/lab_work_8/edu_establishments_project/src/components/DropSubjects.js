import React, { useState, useEffect } from "react"
import { httpHelper } from "../httpHelper"

const DropSubjects = ({ subject_1_id, subject_2_id, subject_3_id, handleValue }) => {
	const [subjects, setSubjects] = useState([])
	const [subject_1, setSubject_1] = useState(subject_1_id)
	const [subject_2, setSubject_2] = useState(subject_2_id)
  const [subject_3, setSubject_3] = useState(subject_3_id)
	const url = "http://localhost:5000/subjects"
	const api = httpHelper()

	useEffect(() => {
		api
			.get(url)
			.then(res => {
				setSubjects([{ id: 0, name: "выберите предмет" }, ...res])
			})
			.catch(err => console.log(err))
	}, [])

	return (
    <>
    <p><label><b>Первый предмет ЦТ:</b>
		<select
			name='subject_1_id'
			value={subject_1}
			onChange={e => {
				setSubject_1(e.target.value)
				handleValue(e)
			}}
		>
			{subjects.map(c => (
				<option value={c.id} key={c.id}>
					{c.name}
				</option>
			))}
		</select></label></p>
    <p><label><b>Второй предмет ЦТ:</b>
    <select
			name='subject_2_id'
			value={subject_2}
			onChange={e => {
				setSubject_2(e.target.value)
				handleValue(e)
			}}
		>
			{subjects.map(c => (
				<option value={c.id} key={c.id}>
					{c.name}
				</option>
			))}
		</select></label></p>
    <p><label><b>Третий предмет ЦТ:</b>
    <select
			name='subject_3_id'
			value={subject_3}
			onChange={e => {
				setSubject_3(e.target.value)
				handleValue(e)
			}}
		>
			{subjects.map(c => (
				<option value={c.id} key={c.id}>
					{c.name}
				</option>
			))}
		</select></label></p>
    </>
	)
}

export default DropSubjects
