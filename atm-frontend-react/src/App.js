import './App.css'
import {useState} from 'react'
import Container from '@material-ui/core/Container'
import Grid from '@material-ui/core/Grid'
import Home from './components/Home'
import Numpad from './components/Numpad'

function App() {

  const [keypadInput, setKeypadInput] = useState("")

  const numpadOnClick = (key) => {
      setKeypadInput(keypadInput + key.key)
      console.log(keypadInput)
      console.log(key)
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
            <Home keypadInput={keypadInput} setKeypadInput={setKeypadInput}></Home>
            <Numpad numpadOnClick={numpadOnClick}></Numpad>
        </Grid>
      </Container>

    </div>
  )
}

export default App
