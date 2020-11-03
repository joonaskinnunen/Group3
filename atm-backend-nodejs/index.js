const express = require('express')
const app = express()

var mysql = require('mysql')
require('dotenv').config()

var connection = mysql.createConnection({
  host     : process.env.DB_HOST,
  user     : process.env.DB_USER,
  password : process.env.DB_PASSWORD,
  port: '8080'
})

connection.connect(function(err) {
  if (err) {
    console.error('error connecting: ' + err.stack);
    return
  }

  console.log('connected as id ' + connection.threadId)
})

connection.end()

let testjson = [
    {
        name: "Joonas",
        id: 1
    }
]

app.get('/', (req, res) => {
    res.send('<h1>Hello World!</h1>')
})

app.get('/api/testroute', (req, res) => {
    res.json(testjson)
})

const PORT = 3001
app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`)
})