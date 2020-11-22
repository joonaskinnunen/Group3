import Button from '@material-ui/core/Button'
import Grid from '@material-ui/core/Grid'
import cardsService from '../services/cards'

const Withdrawal = (props) => {

    const handleWithdrawal = (amount) => {
        if (props.isCreditSelected) {
            if (props.card.creditLimit + props.card.creditBalance > amount) {
                cardsService.creditWithdrawal(amount)
                props.updateMessage(`Nosto onnistui! Tilillä käytettävissä: ${props.card.creditLimit + props.card.creditBalance}€`)
                props.setCard({...props.card, creditBalance: props.card.creditBalance - amount})
                console.log(props.card.creditBalance)
            } else {
                props.updateMessage(`Tilin saldo ei riitä noston tekemiseen! Tilillä käytettävissä: ${props.card.creditLimit + props.card.creditBalance}€`)
            }
        } else {
            if (props.card.debitBalance > amount) {
                cardsService.debitWithdrawal(amount)
                props.updateMessage(`Nosto onnistui! Tilin saldo: ${props.card.debitBalance}€`)
                props.setCard({...props.card, debitBalance: props.card.debitBalance - amount})
                console.log(props.card.debitBalance)
            } else {
                props.updateMessage(`Tilin saldo ei riitä noston tekemiseen! Tilillä käytettävissä: ${props.card.creditLimit + props.card.creditBalance}€`)
            }
        }
    }

    return (
        <>
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <Button variant="contained" size="large" color="primary" onClick={() => handleWithdrawal(20)}>20€</Button>
                <Button variant="contained" size="large" color="primary" onClick={() => handleWithdrawal(40)}>40€</Button>
                <Button variant="contained" size="large" color="primary" onClick={() => handleWithdrawal(50)}>50€</Button>
                <Button variant="contained" size="large" color="primary" onClick={() => handleWithdrawal(100)}>100€</Button>
            </Grid>
        </>
    )
}

export default Withdrawal