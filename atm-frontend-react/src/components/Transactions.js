import { DataGrid } from '@material-ui/data-grid'

const Transactions = (props) => {

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

    return (
        <>
            <h3>TILITAPAHTUMAT</h3>
            <div style={{ display: 'flex', height: '250px', width: '100%' }}>
                <div style={{ flexGrow: 1 }}>
                    <DataGrid sortModel={sortModel} rows={transactions} columns={columns} pageSize={4} />
                </div>
            </div>
        </>
    )
}

export default Transactions