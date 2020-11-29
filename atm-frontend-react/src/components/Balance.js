import Grid from '@material-ui/core/Grid'
import Button from '@material-ui/core/Button'
import { Link } from "react-router-dom"

const Balance = (props) => {

    const handleExit = () => {
        props.setCard(null)
        props.setCardId(null)
        props.setIsCreditSelected(null)
    }

    return (
        <>
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                {props.isCreditSelected ? <h2>Luottoa käytettävissä: {props.card.creditLimit + props.card.creditBalance}€</h2> : <h2>Tilin saldo: {props.card.debitBalance}€</h2>}
                <Button component={Link} to="/" variant="contained" size="large" color="primary" onClick={() => handleExit()}>LOPETA</Button>
            </Grid>
        </>
    )
}

export default Balance