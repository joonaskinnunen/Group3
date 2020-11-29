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
import Deposit from './components/Deposit'
import Balance from './components/Balance'
import Transactions from './components/Transactions'
import Exit from './components/Exit'
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
  const [message, setMessage] = useState(null)
  const [exitMessage, setExitMessage] = useState(null)
  const [messageColor, setMessageColor] = useState("primary")
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
    }, 3000)
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
          <div className="screen">
            <div style={{ minHeight: "32px" }}>
              {message && <Chip color={messageColor} label={message} icon={<ErrorIcon />} />}
            </div>
            <Router>
              <Switch>
                <Route path="/login">
                  <Login updateMessage={updateMessage} setMessageColor={setMessageColor} keypadInput={keypadInput} setKeypadInput={setKeypadInput} cards={cards} cardId={cardId} card={card} setCard={setCard} />
                </Route>
                <Route path="/accountchoice">
                  <AccountChoice setIsCreditSelected={setIsCreditSelected} isCreditSelected={isCreditSelected} setMessage={setMessage} />
                </Route>
                <Route path="/actionchoice">
                  <ActionChoice />
                </Route>
                <Route path="/withdrawal">
                  <Withdrawal keypadInput={keypadInput} setKeypadInput={setKeypadInput} updateMessage={updateMessage} setMessageColor={setMessageColor} card={card} setCard={setCard} isCreditSelected={isCreditSelected} setExitMessage={setExitMessage} exitMessage={exitMessage} />
                </Route>
                <Route path="/deposit">
                  <Deposit keypadInput={keypadInput} setKeypadInput={setKeypadInput} updateMessage={updateMessage} setMessageColor={setMessageColor} card={card} setCard={setCard} isCreditSelected={isCreditSelected} setExitMessage={setExitMessage} exitMessage={exitMessage} />
                </Route>
                <Route path="/balance">
                  <Balance card={card} isCreditSelected={isCreditSelected} />
                </Route>
                <Route path="/transactions">
                  <Transactions card={card} isCreditSelected={isCreditSelected} />
                </Route>
                <Route path="/exit">
                  <Exit setCard={setCard} setCardId={setCardId} exitMessage={exitMessage} setExitMessage={setExitMessage} />
                </Route>
                <Route path="/">
                  <Home updateMessage={updateMessage} setMessageColor={setMessageColor} keypadInput={keypadInput} setKeypadInput={setKeypadInput} cards={cards} cardId={cardId} setCardId={setCardId} />
                </Route>
              </Switch>
            </Router>
          </div>
          <Numpad numpadOnClick={numpadOnClick}></Numpad>
        </Grid>
      </Container>
    </div>
  )
}

export default App
