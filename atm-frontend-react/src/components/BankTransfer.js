import Button from '@material-ui/core/Button'
import Grid from '@material-ui/core/Grid'
import cardsService from '../services/cards'
import TextField from '@material-ui/core/TextField'

const BankTransfer = (props) => {

    const handleWithdrawal = (amount) => {
        if (props.isCreditSelected) {
            if (props.card.creditLimit + props.card.creditBalance > amount) {
                cardsService.creditWithdrawal(amount)
                props.setMessageColor("primary")
                props.updateMessage(`Nosto onnistui! Tilillä käytettävissä: ${props.card.creditLimit + props.card.creditBalance - amount}€`)
                props.setCard({ ...props.card, creditBalance: props.card.creditBalance - amount })
                console.log(props.card.creditBalance)
            } else {
                props.setMessageColor("secondary")
                props.updateMessage(`Tilin saldo ei riitä noston tekemiseen! Tilillä käytettävissä: ${props.card.creditLimit + props.card.creditBalance}€`)
            }
        } else {
            if (props.card.debitBalance > amount) {
                cardsService.debitWithdrawal(amount)
                props.setMessageColor("primary")
                props.updateMessage(`Nosto onnistui! Tilin saldo: ${props.card.debitBalance - amount}€`)
                props.setCard({ ...props.card, debitBalance: props.card.debitBalance - amount })
                console.log(props.card.debitBalance)
            } else {
                props.setMessageColor("secondary")
                props.updateMessage(`Tilin saldo ei riitä noston tekemiseen! Tilin saldo: ${props.card.debitBalance}€`)
            }
        }
    }

    return (
        <>
            <TextField disabled id="outlined-basic" label="Tilinumero" variant="outlined" value={props.keypadInput} />
            <TextField disabled id="outlined-basic" label="Summa" variant="outlined" value={props.keypadInput} />
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <Button disabled={!props.keypadInput} variant="contained" color="primary" onClick={() => handleWithdrawal(props.keypadInput)}>TEE SIIRTO</Button>
                <Button variant="contained" size="small" onClick={() => props.setKeypadInput("")}>TYHJENNÄ</Button>
            </Grid>
        </>
    )
}

export default BankTransfer