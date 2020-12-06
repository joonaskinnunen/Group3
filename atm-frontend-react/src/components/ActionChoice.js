import Button from '@material-ui/core/Button'
import Grid from '@material-ui/core/Grid'
import { Link } from "react-router-dom"

const AccountChoice = (props) => {

    return (
        <>
            <h3>VALITSE TOIMINTO</h3>
            <Grid
                direction="row"
                justify="center"
                alignItems="center"
                container
            >
                <Button component={Link} to="/withdrawal" variant="contained" size="large" color="primary">NOSTO</Button>
                <Button component={Link} to="/balance" variant="contained" size="large" color="primary">SALDO</Button>
                <Button component={Link} to="/transactions" variant="contained" size="large" color="primary">TILITAPAHTUMAT</Button>
                <Button component={Link} to="/deposit" variant="contained" size="large" color="primary">TALLETUS</Button>
                <Button component={Link} to="/banktransfer" variant="contained" size="large" color="primary">TILISIIRTO</Button>
            </Grid>
        </>
    )
}

export default AccountChoice