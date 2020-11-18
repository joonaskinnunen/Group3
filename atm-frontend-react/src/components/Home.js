import Button from '@material-ui/core/Button'
import TextField from '@material-ui/core/TextField'

const Home = () => {
    return (
        <>
            <p>Syötä kortin numero:</p>
            <TextField id="outlined-basic" label="Kortti ID" variant="outlined" />
            <Button variant="contained" color="primary">JATKA</Button>
        </>
    )
}

export default Home