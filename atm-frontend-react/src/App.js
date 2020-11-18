import './App.css'
import {useState, useEffect} from 'react'
import Container from '@material-ui/core/Container'
import Grid from '@material-ui/core/Grid'
import Home from './components/Home'
import Numpad from './components/Numpad'
import cardService from "./services/cards"

function App() {

  const [keypadInput, setKeypadInput] = useState("")
  const [cards, setCards] = useState([])
  const [selectedCard, setSelectedCard] = useState({})
  const [message, setMessage] = useState("")

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
            <p>{message}</p>
            <Home setMessage={setMessage} keypadInput={keypadInput} setKeypadInput={setKeypadInput} cards={cards} setSelectedCard={setSelectedCard}></Home>
            <Numpad numpadOnClick={numpadOnClick}></Numpad>
        </Grid>
      </Container>

    </div>
  )
}

export default App
