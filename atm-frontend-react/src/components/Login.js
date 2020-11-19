import Button from '@material-ui/core/Button'
import TextField from '@material-ui/core/TextField'
import Grid from '@material-ui/core/Grid'
import loginService from '../services/login'

const Login = (props) => {

    const handleLogin = async (event) => {
        try {
            const cardId = props.cardId
            const keypadInput = props.keypadInput
            const card = await loginService.login({
                cardId, pin: keypadInput
            })
            props.setCard(card)
            console.log(props.card)
        } catch (exception) {
            props.updateMessage('Väärä pin-koodi!')
        }
        props.setKeypadInput("")
    }

    return (
        <>
            <p>Syötä pin-koodi:</p>
            <TextField disabled id="outlined-basic" label="PIN" variant="outlined" value={props.keypadInput} />
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <Button variant="contained" size="large" color="primary" onClick={() => handleLogin()}>KIRJAUDU</Button>
                <Button variant="contained" size="small" onClick={() => props.setKeypadInput("")}>TYHJENNÄ</Button>
            </Grid>
        </>
    )
}

export default Login;