const cardsRouter = require('express').Router()
const Card = require('../models/card')
const CreditAccount = require('../models/creditaccount')
const DebitAccount = require('../models/debitaccount')

cardsRouter.get('/', async (request, response) => {
  const cards = await Card.find({}).populate('creditAccountId').populate('debitAccountId')
  response.json(cards.map(card => card.toJSON()))
})

cardsRouter.post('/', async (request, response) => {
  const body = request.body

  const creditAccount = await CreditAccount.findById(body.creditAccountId)
  const debitAccount = await DebitAccount.findById(body.debitAccountId)

  const card = new Card({
    cardId: body.cardId,
    owner: body.owner,
    pin: body.pin,
    debitAccountId: creditAccount._id,
    creditAccountId: debitAccount._id
  })

  const savedCard = await card.save()
  response.json(savedCard.toJSON())
})

cardsRouter.get('/:id', async (request, response) => {
  const card = await Card.findById(request.params.id)
  if (card) {
    response.json(card.toJSON())
  } else {
    response.status(404).end()
  }
})

module.exports = cardsRouter