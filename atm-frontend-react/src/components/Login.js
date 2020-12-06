import Button from '@material-ui/core/Button'
import TextField from '@material-ui/core/TextField'
import Grid from '@material-ui/core/Grid'
import { Redirect } from "react-router-dom"
import loginService from '../services/login'
import cardsService from '../services/cards'

const Login = (props) => {

    const handleLogin = async (event) => {
        try {
            const cardId = props.cardId
            const keypadInput = props.keypadInput
            const card = await loginService.login({
                cardId, pin: keypadInput
            })
            card.creditTransactions.forEach((item) => {
                item.time = new Date(item.time)
            })
            card.debitTransactions.forEach((item) => {
                item.time = new Date(item.time)
            })
            props.setCard(card)
            console.log(props.card)
            console.log(card.token)
            cardsService.setToken(card.token)
            props.setMessageColor("primary")
            props.updateMessage(`Tervetuloa ${card.owner}!`)
        } catch (exception) {
            props.setMessageColor("secondary")
            props.updateMessage('Väärä pin-koodi!')
        }
        props.setKeypadInput("")
    }

    return (
        <>
            {props.card != null && <Redirect to="/accountchoice" />}
            <h3>Syötä pin-koodi:</h3>
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