import './App.css'
import { useState, useEffect } from 'react'
import Container from '@material-ui/core/Container'
import Grid from '@material-ui/core/Grid'
import Home from './components/Home'
import Login from './components/Login'
import Numpad from './components/Numpad'
import cardService from "./services/cards"
import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link
} from "react-router-dom"

function App() {

  const [keypadInput, setKeypadInput] = useState("")
  const [cards, setCards] = useState([])
  const [card, setCard] = useState(null)
  const [cardId, setCardId] = useState(null)
  const [pin, setPin] = useState(null)
  const [loggedIn, setLoggedIn] = useState(false)
  const [message, setMessage] = useState(null)

  useEffect(() => {
    cardService
      .getAll()
      .then(initialCards => {
        setCards(initialCards)
      })
  }, [])

  const numpadOnClick = (key) => {
    setKeypadInput(keypadInput + key.key)
    console.log(keypadInput)
    console.log(key)
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
          {message && <p>{message}</p>}
          <Router>
            <Switch>
              <Route path="/login">
                <Login updateMessage={updateMessage} keypadInput={keypadInput} setKeypadInput={setKeypadInput} cards={cards} cardId={cardId} card={card} setCard={setCard} />
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
