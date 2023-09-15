import {Redirect} from 'react-router-dom';
import {useDispatch} from 'react-redux'
import { useAuth } from 'hooks/use-auth';
import {removeUser} from 'store/slices/userSlice'
import { Link } from 'react-router-dom/cjs/react-router-dom.min';
import CrudAddSpeciality from 'components/CrudAddSpeciality';
const AddSpecialityPage = () => {
   
    const dispatch = useDispatch();

    const {isAuth, email} = useAuth();

    return isAuth ? (
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
        < CrudAddSpeciality />
			</main>
    </>
        </div>
    ) : (
        <Redirect to="/login" />
    )
}

export default AddSpecialityPage