import { Login } from 'components/Login';
import { Link } from 'react-router-dom';

const LoginPage = () => {
    return (
        <div class ="form">
            <h1>Вход</h1>
            <Login />
            <p>
                Еще нет аккаунта? <Link to="/register"> Регистрация</Link>
            </p>
        </div>
    )
}

export default LoginPage