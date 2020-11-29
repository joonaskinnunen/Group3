import Button from '@material-ui/core/Button'
import TextField from '@material-ui/core/TextField'
import Grid from '@material-ui/core/Grid'
import { Redirect } from "react-router-dom"

const Home = (props) => {

    const onSubmitClick = () => {
        let foundedCard = null
        props.cards.map(card => {
            if (card.cardId == props.keypadInput) foundedCard = card.cardId
        })
        if (foundedCard == null) {
            props.setMessageColor("secondary")
            props.updateMessage("Virheellinen kortin numero")
        } else {
            props.setCardId(foundedCard)
        }
        props.setKeypadInput("")
    }

    return (
        <>
            {props.cardId != null && <Redirect to="/login" />}
            <p>Syötä kortin numero:</p>
            <TextField disabled id="outlined-basic" label="Kortti ID" variant="outlined" value={props.keypadInput} />
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <Button variant="contained" size="large" color="primary" onClick={() => onSubmitClick()}>JATKA</Button>
                <Button variant="contained" size="small" onClick={() => props.setKeypadInput("")}>TYHJENNÄ</Button>
            </Grid>
        </>
    )
}

export default Home