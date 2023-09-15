import {Redirect} from 'react-router-dom';
import {useDispatch} from 'react-redux'
import { useAuth } from 'hooks/use-auth';
import {removeUser} from 'store/slices/userSlice'
import { Link } from 'react-router-dom/cjs/react-router-dom.min';
import CrudListSpeciality from 'components/CrudListSpeciality'
import CrudListEstablishments from 'components/CrudListEstablishments';
import {useState} from 'react';
const HomePage = () => {
  const [establishments, setEstablishments] = useState([])
  const [emails, setEmail] = useState('');
  const [pass, setPass] = useState('');
  const dispatch = useDispatch();
  const [s1, setS1] = useState('');
  const [s2, setS2] = useState('');
  const [s3, setS3] = useState('');
  const {isAuth, email} = useAuth();
  console.log(email)
  let fl = false

  let content = isAuth ? (
    <div>
        <>
  <header>
    <div className='header__content'>
       
      <div className='logo'>
        УЧЕБНЫЕ ЗАВЕДЕНИЯ.ОНЛАЙН
        <div className='linkk'>
        <Link to="requests"><button class = "but_j">Запросы</button></Link>
        <Link to="/all_spec"><button class = "but_j1">Учебные заведения</button></Link>
        <Link to="/"><button class = "but_j" >Специальности</button></Link>
        <button className='but_j2'onClick={()=> dispatch(removeUser())}>Выход </button>
        </div>
        
      </div>
    </div>
    
  </header>
  <main>
    <h1>Подбор специальностей по предметам ЦТ</h1>
    <p class = "but_1"><Link to="add_spec"><button class = "but">Добавить специальность</button></Link></p>
    <div class="choose_subjects_panel">
      <h2>Выберите вступительные испытания</h2>
  <p><label className = "choose_subj"> Первый предмет ЦТ:
    <select
    сlass = "choose"
			value={s1}
			onChange={e => {
				setS1(e.target.value)
			}}
		>  <option value="0">Выберите предмет</option>
			 <option value="1">математика</option>
                    <option value="2">русский язык</option>
                    <option value="3">белорусский язык</option>
                    <option value="4">физика</option>
                    <option value="5">химия</option>
                    <option value="6">история Беларуси</option>
                    <option value="7">всемирная история</option>
                    <option value="8">география</option>
                    <option value="9">обществоведение</option>
                    <option value="10">биология</option>
                    <option value="11">иностранный язык</option>
		</select>
    </label>
    </p>
    <p>
    <label className = "choose_subj"> Второй предмет ЦТ:
      <select сlassname = "choose"
			value={s2}
			onChange={e => {
				setS2(e.target.value)
			}}
		>  <option value="0">Выберите предмет</option>
			 <option value="1">математика</option>
                    <option value="2">русский язык</option>
                    <option value="3">белорусский язык</option>
                    <option value="4">физика</option>
                    <option value="5">химия</option>
                    <option value="6">история Беларуси</option>
                    <option value="7">всемирная история</option>
                    <option value="8">география</option>
                    <option value="9">обществоведение</option>
                    <option value="10">биология</option>
                    <option value="11">иностранный язык</option>
		</select>
    </label></p>
    <p>
    <label className = "choose_subj"> Третий предмет ЦТ:
            <select
            сlassname = "choose"
			name='establishmentsId'
			value={s3}
			onChange={e => {
				setS3(e.target.value)
			}}
		>  <option value="0">Выберите предмет</option>
			 <option value="1">математика</option>
                    <option value="2">русский язык</option>
                    <option value="3">белорусский язык</option>
                    <option value="4">физика</option>
                    <option value="5">химия</option>
                    <option value="6">история Беларуси</option>
                    <option value="7">всемирная история</option>
                    <option value="8">география</option>
                    <option value="9">обществоведение</option>
                    <option value="10">биология</option>
                    <option value="11">иностранный язык</option>
		</select>
    </label></p>
    </div>
    <CrudListSpeciality num1={s1} num2={s2} num3={s3}/>
    
 
  </main>
</>
    </div>
) : (
    <Redirect to="/login" />
)
  return content
}

export default HomePage