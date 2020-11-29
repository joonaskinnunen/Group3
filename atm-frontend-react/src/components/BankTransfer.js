import Button from '@material-ui/core/Button'
import cardsService from '../services/cards'
import TextField from '@material-ui/core/TextField'
import { Redirect } from "react-router-dom"
import { useState } from 'react'

const BankTransfer = (props) => {

    const [cardFound, setCardFound] = useState(null)

    const checkAccountId = () => {
        let found = false
        props.cards.map(card => {
            if (card.cardId == props.keypadInput) {
                console.log(card.cardId)
                console.log(props.keypadInput)
                setCardFound(card.cardId)
                found = true
            }
        })
        if (!found) {
            props.updateMessage("Virheellinen tilinumero!")
        }
        props.setKeypadInput("")
    }

    const handleTransfer = (amount) => {
        if (props.card.debitBalance > amount) {
            cardsService.bankTransfer(amount, cardFound)
            props.setMessageColor("primary")
            props.setExitMessage(`Tilisiirto onnistui! Tilin saldo: ${props.card.debitBalance - amount}€`)
            props.setCard({ ...props.card, debitBalance: props.card.debitBalance - amount })
            console.log(props.card.debitBalance)
        } else {
            props.setMessageColor("secondary")
            props.updateMessage(`Tilin saldo ei riitä noston tekemiseen! Tilin saldo: ${props.card.debitBalance}€`)
        }
        props.setKeypadInput("")
    }

    return (
        <> 
            {props.exitMessage != null && <Redirect to="/exit" />}
            {cardFound ? <h3>Syötä summa</h3> : <h3>Syötä tilinumero</h3>}
            {props.exitMessage != null && <Redirect to="/exit" />}
            <TextField disabled id="outlined-basic" variant="outlined" value={props.keypadInput} />
            <br />
            {cardFound ? <Button disabled={!props.keypadInput} variant="contained" color="primary" onClick={() => handleTransfer(props.keypadInput)}>HYVÄKSY</Button> : <Button disabled={!props.keypadInput} variant="contained" color="primary" onClick={() => checkAccountId(props.keypadInput)}>JATKA</Button>}
            <Button variant="contained" size="small" onClick={() => props.setKeypadInput("")}>TYHJENNÄ</Button>
        </>
    )
}

export default BankTransfer