import { DataGrid } from '@material-ui/data-grid'
import Button from '@material-ui/core/Button'
import { Link } from "react-router-dom"

const Transactions = (props) => {

    const handleExit = () => {
        props.setCard(null)
        props.setCardId(null)
        props.setMessageDivHeight("32px")
    }

    const columns = [
        { field: 'id', headerName: 'ID', width: 50 },
        { field: 'amount', headerName: 'Summa', width: 100 },
        { field: 'time', headerName: 'Aika', width: 200 },
        { field: 'type', headerName: 'Tyyppi', width: 110 }
    ]

    const sortModel = [
        {
            field: 'id',
            sort: 'desc'
        },
    ];

    const transactions = props.isCreditSelected ? props.card.creditTransactions : props.card.debitTransactions

    transactions.map((transaction, index) => {
        transaction.type = transaction.amount < 0 ? "Nosto" : "Talletus"
        transaction.id = index
        /*    let date = new Date(transaction.time)
            let dateStr = date.getDate() + '.' + date.getMonth() + '.' + date.getFullYear()
            console.log(dateStr)
            console.log(date.getDate() + '.' + date.getMonth() + '.' + date.getFullYear())
            console.log(date.toLocaleString())
            transaction.time = `${date.toLocaleString()}`
            console.log(transaction.time) */
    })

    props.setMessageDivHeight(0)

    return (
        <>
            <h3>TILITAPAHTUMAT</h3>
            <div style={{ display: 'flex', height: '210px', width: '100%' }}>
                <div style={{ flexGrow: 1 }}>
                    <DataGrid sortModel={sortModel} rows={transactions} columns={columns} pageSize={4} />
                </div>
            </div>
            <Button component={Link} to="/" variant="contained" size="large" color="primary" onClick={() => handleExit()}>LOPETA</Button>
        </>
    )
}

export default Transactions