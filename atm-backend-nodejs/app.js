const express = require('express')
const app = express()
const mongoose = require('mongoose')
const cors = require('cors')
const cardsRouter = require('./controllers/cards')
const debitAccountsRouter = require('./controllers/debitaccounts')
const creditAccountsRouter = require('./controllers/creditaccounts')
require('dotenv').config()

console.log('connecting to', process.env.MONGODB_URI)

mongoose.connect(process.env.MONGODB_URI, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => {
    console.log('connected to MongoDB')
  })
  .catch((error) => {
    console.log('error connection to MongoDB:', error.message)
  })

app.use(cors())
app.use(express.json())

app.use('/api/cards', cardsRouter)
app.use('/api/debitaccounts', debitAccountsRouter)
app.use('/api/creditaccounts', creditAccountsRouter)

module.exports = app