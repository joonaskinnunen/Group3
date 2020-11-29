import Button from '@material-ui/core/Button'
import Grid from '@material-ui/core/Grid'
import cardsService from '../services/cards'
import TextField from '@material-ui/core/TextField'

const Deposit = (props) => {

    const handleDeposit = (amount) => {
        props.setMessageColor("primary")
        if (props.isCreditSelected) {
                cardsService.creditDeposit(amount)
                props.updateMessage(`Talletus onnistui! Tilillä käytettävissä: ${props.card.creditLimit + props.card.creditBalance + parseInt(amount)}€`)
                props.setCard({ ...props.card, creditBalance: props.card.creditBalance + amount })
        } else {
                cardsService.debitDeposit(amount)
                props.updateMessage(`Talletus onnistui! Tilin saldo: ${props.card.debitBalance + parseInt(amount)}€`)
                props.setCard({ ...props.card, debitBalance: props.card.debitBalance + amount })
        }
        props.setKeypadInput("")
    }

    return (
        <>
        <h3>TALLETUS</h3>
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <Button variant="contained" size="large" color="primary" onClick={() => handleDeposit(20)}>20€</Button>
                <Button variant="contained" size="large" color="primary" onClick={() => handleDeposit(40)}>40€</Button>
                <Button variant="contained" size="large" color="primary" onClick={() => handleDeposit(50)}>50€</Button>
                <Button variant="contained" size="large" color="primary" onClick={() => handleDeposit(100)}>100€</Button>
            </Grid>
            <TextField disabled id="outlined-basic" label="Muu summa" variant="outlined" value={props.keypadInput} />
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <Button disabled={!props.keypadInput} variant="contained" color="primary" onClick={() => handleDeposit(props.keypadInput)}>MUU SUMMA</Button>
                <Button variant="contained" size="small" onClick={() => props.setKeypadInput("")}>TYHJENNÄ</Button>
            </Grid>
        </>
    )
}

export default Deposit