import Button from '@material-ui/core/Button'
import Grid from '@material-ui/core/Grid'
import { Redirect } from "react-router-dom"

const AccountChoice = (props) => {

    return (
        <>
            {props.isCreditSelected != null && <Redirect to="/actionchoice" />}
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <Button variant="contained" size="large" color="primary" onClick={() => props.setIsCreditSelected(false)}>DEBIT</Button>
                <Button variant="contained" size="large" color="primary" onClick={() => props.setIsCreditSelected(true)}>CREDIT</Button>
            </Grid>
        </>
    )
}

export default AccountChoice;