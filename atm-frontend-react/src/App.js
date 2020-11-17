import './App.css'
import Container from '@material-ui/core/Container'
import Grid from '@material-ui/core/Grid'

function App() {
  return (
    <div className="App">
      <Container maxWidth="sm"
      id="main-container">
        <Grid
          id="main-grid"
          container
          direction="column"
          justify="center"
          alignItems="center">
            <p>Testi</p>
            <p>Toinen</p>
        </Grid>
      </Container>

    </div>
  )
}

export default App;
