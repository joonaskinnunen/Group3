const cardsRouter = require('express').Router()
const Card = require('../models/card')
const bcrypt = require('bcrypt')
require('dotenv').config()

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

  const saltRounds = 10
  const pinHash = await bcrypt.hash(body.pin, saltRounds)

  const card = new Card({
    cardId: body.cardId,
    owner: body.owner,
    pinHash,
    debitBalance: body.debitBalance,
    creditBalance: 0,
    creditLimit: body.creditLimit,
    debitTransactions: [],
    creditTransactions: []
  })

  const savedCard = await card.save()
  response.json(savedCard.toJSON())
})
cardsRouter.put('/debitwithdrawal/:id', async (request, response) => {
  const body = request.body

  const card = await Card.findOne({ cardId: request.params.id })
  console.log(card)
  console.log(request.params.id)

  const filter = { cardId: request.params.id };
  const update = { $inc: { "debitBalance": -body.amount }, $push: { debitTransactions: { time: new Date().toUTCString(), amount: "-" + body.amount } } };

  const passwordCorrect = card === null
    ? false
    : await bcrypt.compare(body.pin, card.pinHash)

  if (!(card && passwordCorrect)) {
    return response.status(401).json({
      error: 'invalid username or password'
    })
  }

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
    .then(updatedCard => {
      response.json(updatedCard.toJSON())
    })
    .catch(error => console.log(error))
})

cardsRouter.put('/creditwithdrawal/:id', async (request, response) => {
  const body = request.body

  const card = await Card.findOne({ cardId: request.params.id })

  const filter = { cardId: request.params.id };
  const update = { $inc: { "creditBalance": -body.amount }, $push: { creditTransactions: { time: new Date().toUTCString(), amount: "-" + body.amount } } };

  const passwordCorrect = card === null
    ? false
    : await bcrypt.compare(body.pin, card.pinHash)

  if (!(card && passwordCorrect)) {
    return response.status(401).json({
      error: 'invalid username or password'
    })
  }

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
    .then(updatedCard => {
      response.json(updatedCard.toJSON())
    })
    .catch(error => console.log(error))
})

cardsRouter.put('/debitdeposit/:id', async (request, response) => {
  const body = request.body

  const card = await Card.findOne({ cardId: request.params.id })

  const filter = { cardId: request.params.id };
  const update = { $inc: { "debitBalance": body.amount }, $push: { debitTransactions: { time: new Date().toUTCString(), amount: "+" + body.amount } } };

  const passwordCorrect = card === null
    ? false
    : await bcrypt.compare(body.pin, card.pinHash)

  if (!(card && passwordCorrect)) {
    return response.status(401).json({
      error: 'invalid username or password'
    })
  }

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
    .then(updatedCard => {
      response.json(updatedCard.toJSON())
    })
    .catch(error => console.log(error))
})

cardsRouter.put('/creditdeposit/:id', async (request, response) => {
  const body = request.body

  const card = await Card.findOne({ cardId: request.params.id })

  const filter = { cardId: request.params.id };
  const update = { $inc: { "creditBalance": body.amount }, $push: { creditTransactions: { time: new Date().toUTCString(), amount: "+" + body.amount } } };

  const passwordCorrect = card === null
    ? false
    : await bcrypt.compare(body.pin, card.pinHash)

  if (!(card && passwordCorrect)) {
    return response.status(401).json({
      error: 'invalid username or password'
    })
  }

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
    .then(updatedCard => {
      response.json(updatedCard.toJSON())
    })
    .catch(error => console.log(error))
})

module.exports = cardsRouter