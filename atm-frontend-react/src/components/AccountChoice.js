import Button from '@material-ui/core/Button'
import Grid from '@material-ui/core/Grid'
import { Redirect } from "react-router-dom"

const AccountChoice = (props) => {

    const handleAccountChoice = (creditSelected) => {
        creditSelected ? props.setIsCreditSelected(true) : props.setIsCreditSelected(false)
        props.setMessage(null)
    }

    return (
        <>
            <h3>VALITSE TILI</h3>
            {props.isCreditSelected != null && <Redirect to="/actionchoice" />}
            <Grid
                direction="row"
                justify="center"
            >
                <Button variant="contained" size="large" color="primary" onClick={() => handleAccountChoice(false)}>DEBIT</Button>
                <Button variant="contained" size="large" color="primary" onClick={() => handleAccountChoice(true)}>CREDIT</Button>
            </Grid>
        </>
    )
}

export default AccountChoice;