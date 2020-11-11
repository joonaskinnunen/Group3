const cardsRouter = require('express').Router()
const Card = require('../models/card')

cardsRouter.get('/', async (request, response) => {
  const cards = await Card.find({})
  response.json(cards.map(card => card.toJSON()))
})

cardsRouter.get('/:id', async (request, response) => {
  const card = await Card.findById(request.params.id)
  if (card) {
    response.json(card.toJSON())
  } else {
    response.status(404).end()
  }
})

cardsRouter.post('/', async (request, response) => {
  const body = request.body

  const card = new Card({
    cardId: body.cardId,
    owner: body.owner,
    pin: body.pin,
    debitBalance: body.debitBalance,
    creditBalance: 0,
    creditLimit: body.creditLimit,
    debitTransactions: [],
    creditTransactions: []
  })

  const savedCard = await card.save()
  response.json(savedCard.toJSON())
})

cardsRouter.put('/debitwithdrawal/:id', async (request, response, next) => {
  const body = request.body

  const filter = { cardId: request.params.id };
  const update = {$inc: { "debitBalance" : -body.amount }};

  let card = await Card.findOneAndUpdate(filter, update, {
    new: true
  })
  .then(updatedCard => {
    response.json(updatedCard.toJSON())
  })
  .catch(error => next(error))
})

cardsRouter.put('/creditwithdrawal/:id', async (request, response, next) => {
  const body = request.body

  const filter = { cardId: request.params.id };
  const update = {$inc: { "creditBalance" : -body.amount }};

  let card = await Card.findOneAndUpdate(filter, update, {
    new: true
  })
  .then(updatedCard => {
    response.json(updatedCard.toJSON())
  })
  .catch(error => next(error))
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