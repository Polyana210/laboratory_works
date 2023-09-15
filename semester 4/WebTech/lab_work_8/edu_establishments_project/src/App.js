import {Switch, Route} from 'react-router-dom';
import './App.css';
import HomePage from 'pages/HomePage';
import LoginPage from 'pages/LoginPage';
import RegisterPage from 'pages/RegisterPage';
import AddRequestPage from 'pages/AddRequestPage';
import RequestsPage from 'pages/RequestsPage';
import AddSpecialityPage from 'pages/AddSpecialityPage';
import AllSpecialitiesPage from 'pages/AllSpecialitiesPage';
function App() {
  
  return (
    <Switch>
      <Route exact path="/" component={HomePage} />
      <Route exact path="/login" component={LoginPage} />
      <Route exact path="/register" component={RegisterPage} />
      <Route exact path="/add" component={AddRequestPage} />
      <Route exact path="/requests" component={RequestsPage} />
      <Route exact path="/add_spec" component={AddSpecialityPage} />
      <Route exact path="/all_spec" component={AllSpecialitiesPage} />
      <Route exact path="/spec_page" component={AllSpecialitiesPage} />
    </Switch>
  );
}

export default App;
