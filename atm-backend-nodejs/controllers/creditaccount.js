const creditAccountsRouter = require('express').Router()
const CreditAccount = require('../models/creditaccount')

creditAccountsRouter.get('/', async (request, response) => {
  const accounts = await CreditAccount.find({}).populate('transactions')
  response.json(accounts.map(account => account.toJSON()))
})

creditAccountsRouter.post('/', async (request, response) => {
  const body = request.body

  const account = new DebitAccount({
    balance: body.balance,
    creditLimit: body.creditLimit,
    transactions: []
  })

  const savedAccount = await account.save()
  response.json(savedAccount.toJSON())
})

creditAccountsRouter.get('/:id', async (request, response) => {
  const account = await CreditAccount.findById(request.params.id)
  if (account) {
    response.json(account.toJSON())
  } else {
    response.status(404).end()
  }
})

module.exports = creditAccountsRouter