import Button from '@material-ui/core/Button'
import TextField from '@material-ui/core/TextField'
import Grid from '@material-ui/core/Grid'

const Home = (props) => {

    const onSubmitClick = () => {
        let foundedCard = null
        props.cards.map(card => {
            if(card.cardId == props.keypadInput) foundedCard = card
        })
        foundedCard == null ? props.setMessage("Virheellinen kortin numero") : props.setSelectedCard(foundedCard)
        props.setKeypadInput("")
    }

    return (
        <>
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