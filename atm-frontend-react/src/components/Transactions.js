import { DataGrid } from '@material-ui/data-grid'

const Transactions = (props) => {

    const columns = [
        { field: 'id', headerName: 'ID', width: 50 },
        { field: 'amount', headerName: 'Summa', width: 100 },
        { field: 'time', headerName: 'Aika', width: 200 },
        { field: 'type', headerName: 'Tyyppi', width: 110 }
    ]

    const transactions = props.isCreditSelected ? props.card.creditTransactions : props.card.debitTransactions

    transactions.map((transaction, index) => {
        transaction.type = transaction.amount < 0 ? "Nosto" : "Talletus"
        transaction.id = index
        let date = new Date(transaction.time)
        let dateStr = date.toString().toLocaleString()
        console.log(dateStr)
        console.log(date)
        console.log(date.toLocaleString())
        transaction.time = dateStr
    })

    return (
        <>
            <div style={{ display: 'flex', height: '300px', width: '100%' }}>
  <div style={{ flexGrow: 1 }}>
                <DataGrid rows={transactions} columns={columns} pageSize={5} />
            </div>
            </div>
        </>
    )
}

export default Transactions