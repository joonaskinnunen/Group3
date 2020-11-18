import Button from '@material-ui/core/Button'
import TextField from '@material-ui/core/TextField'
import Grid from '@material-ui/core/Grid'

const Login = (props) => {

    const onSubmitClick = () => {

    }

    return (
        <>
            <p>Syötä pin-koodi:</p>
            <TextField disabled id="outlined-basic" label="PIN" variant="outlined" value={props.keypadInput} />
            <Grid
                direction="row"
                justify="space-between"
                alignItems="center"
            >
                <Button variant="contained" size="large" color="primary" onClick={() => onSubmitClick()}>KIRJAUDU</Button>
                <Button variant="contained" size="small" onClick={() => props.setKeypadInput("")}>TYHJENNÄ</Button>
            </Grid>
        </>
    )
}

export default Login;