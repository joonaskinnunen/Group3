import Grid from '@material-ui/core/Grid'
import Button from '@material-ui/core/Button'
import { Link } from "react-router-dom"

const Exit = (props) => {

    const handleExit = () => {
        props.setCard(null)
        props.setCardId(null)
        props.setExitMessage(null)
        props.setIsCreditSelected(null)
    }

    return (
        <>
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <h3>Kiitos automaatin käytöstä!</h3>
                <p>{props.exitMessage}</p>
                <Button component={Link} to="/" variant="contained" size="large" color="primary" onClick={() => handleExit()}>LOPETA</Button>
            </Grid>
        </>
    )
}

export default Exit