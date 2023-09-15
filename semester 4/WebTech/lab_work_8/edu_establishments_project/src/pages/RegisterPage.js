import { SignUp } from 'components/SignUp';
import { Link } from 'react-router-dom';

const RegisterPage = () => {
    return (
        <div class="form">
            <h1>Регистрация</h1>
            <SignUp />
            <p>
                Уже есть аккаунт? <Link to="/login">Вход</Link>   
            </p>            
        </div>
    )
}

export default RegisterPage