import './App.css'
import { useState, useEffect } from 'react'
import Container from '@material-ui/core/Container'
import Chip from '@material-ui/core/Chip'
import Grid from '@material-ui/core/Grid'
import ErrorIcon from '@material-ui/icons/Error'
import Home from './components/Home'
import Login from './components/Login'
import AccountChoice from './components/AccountChoice'
import ActionChoice from './components/ActionChoice'
import Withdrawal from './components/Withdrawal'
import Numpad from './components/Numpad'
import cardsService from "./services/cards"
import {
  BrowserRouter as Router,
  Switch,
  Route,
} from "react-router-dom"

function App() {

  const [keypadInput, setKeypadInput] = useState("")
  const [cards, setCards] = useState([])
  const [card, setCard] = useState(null)
  const [cardId, setCardId] = useState(null)
  const [pin, setPin] = useState(null)
  const [loggedIn, setLoggedIn] = useState(false)
  const [message, setMessage] = useState(null)
  const [isCreditSelected, setIsCreditSelected] = useState(null)
 
  useEffect(() => {
    cardsService
      .getAll()
      .then(initialCards => {
        setCards(initialCards)
      })
  }, [])

  const numpadOnClick = (key) => {
    setKeypadInput(keypadInput + key.key)
    console.log(keypadInput)
    console.log(key)
    console.log(card)
    console.log(cards)
  }

  const updateMessage = (newMessage) => {
    setMessage(newMessage)
    setTimeout(() => {
      setMessage(null)
    }, 5000)
  }

  return (
    <div className="App">
      <Container maxWidth="sm"
        id="main-container">
        <Grid
          id="main-grid"
          container
          direction="column"
          justify="center"
          alignItems="center"
          spacing={10}>
          <h1>ATM</h1>
          {message && <Chip color="secondary" label={message} icon={<ErrorIcon />}/>}
          <Router>
            <Switch>
              <Route path="/login">
                <Login updateMessage={updateMessage} keypadInput={keypadInput} setKeypadInput={setKeypadInput} cards={cards} cardId={cardId} card={card} setCard={setCard} />
              </Route>
              <Route path="/accountchoice">
                <AccountChoice setIsCreditSelected={setIsCreditSelected} isCreditSelected={isCreditSelected} />
              </Route>
              <Route path="/actionchoice">
                <ActionChoice />
              </Route>
              <Route path="/withdrawal">
                <Withdrawal updateMessage={updateMessage} card={card} setCard={setCard} isCreditSelected={isCreditSelected} />
              </Route>
              <Route path="/">
                <Home updateMessage={updateMessage} keypadInput={keypadInput} setKeypadInput={setKeypadInput} cards={cards} cardId={cardId} setCardId={setCardId} />
              </Route>
            </Switch>
          </Router>
          <Numpad numpadOnClick={numpadOnClick}></Numpad>
        </Grid>
      </Container>
    </div>
  )
}

export default App
