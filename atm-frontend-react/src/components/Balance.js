import Grid from '@material-ui/core/Grid'

const Balance = (props) => {

    return (
        <>
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                {props.isCreditSelected ? <h2>Luottoa käytettävissä: {props.card.creditLimit + props.card.creditBalance}€</h2> : <h2>Tilin saldo: {props.card.debitBalance}€</h2>}
            </Grid>
        </>
    )
}

export default Balance