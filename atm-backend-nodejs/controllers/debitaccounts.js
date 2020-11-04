const debitAccountsRouter = require('express').Router()
const DebitAccount = require('../models/debitaccount')

debitAccountsRouter.get('/', async (request, response) => {
  const accounts = await DebitAccount.find({}).populate('transactions')
  response.json(accounts.map(account => account.toJSON()))
})

debitAccountsRouter.post('/', async (request, response) => {
  const body = request.body

  const account = new DebitAccount({
    accountId: body.accountId,
    balance: body.balance
  })

  const savedAccount = await account.save()
  response.json(savedAccount.toJSON())
})

debitAccountsRouter.get('/:id', async (request, response) => {
  const account = await DebitAccount.findById(request.params.id)
  if (account) {
    response.json(account.toJSON())
  } else {
    response.status(404).end()
  }
})

module.exports = debitAccountsRouter