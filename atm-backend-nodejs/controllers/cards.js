const cardsRouter = require('express').Router()
const Card = require('../models/card')
const bcrypt = require('bcrypt')
require('dotenv').config()
const jwt = require('jsonwebtoken')

const getTokenFrom = request => {
  const authorization = request.get('authorization')
  if (authorization && authorization.toLowerCase().startsWith('bearer ')) {
    return authorization.substring(7)
  }
  return null
}

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
cardsRouter.put('/debitwithdrawal', async (request, response) => {
  const body = request.body

  const token = getTokenFrom(request)
  const decodedToken = jwt.verify(token, process.env.SECRET)
  if (!token || !decodedToken.cardId) {
    return response.status(401).json({ error: 'token missing or invalid' })
  }

  const filter = { cardId: decodedToken.cardId };
  const update = { $inc: { "debitBalance": -body.amount }, $push: { debitTransactions: { time: new Date().toUTCString(), amount: "-" + body.amount } } };

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
    .then(updatedCard => {
      response.json(updatedCard.toJSON())
    })
    .catch(error => console.log(error))
})

cardsRouter.put('/creditwithdrawal', async (request, response) => {
  const body = request.body

  const token = getTokenFrom(request)
  const decodedToken = jwt.verify(token, process.env.SECRET)
  if (!token || !decodedToken.cardId) {
    return response.status(401).json({ error: 'token missing or invalid' })
  }

  const filter = { cardId: decodedToken.cardId };
  const update = { $inc: { "creditBalance": -body.amount }, $push: { creditTransactions: { time: new Date().toUTCString(), amount: "-" + body.amount } } };

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
    .then(updatedCard => {
      response.json(updatedCard.toJSON())
    })
    .catch(error => console.log(error))
})

cardsRouter.put('/debitdeposit', async (request, response) => {
  const body = request.body

  const token = getTokenFrom(request)
  const decodedToken = jwt.verify(token, process.env.SECRET)
  if (!token || !decodedToken.cardId) {
    return response.status(401).json({ error: 'token missing or invalid' })
  }

  const filter = { cardId: decodedToken.cardId };
  const update = { $inc: { "debitBalance": body.amount }, $push: { debitTransactions: { time: new Date().toUTCString(), amount: "+" + body.amount } } };

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
    .then(updatedCard => {
      response.json(updatedCard.toJSON())
    })
    .catch(error => console.log(error))
})

cardsRouter.put('/creditdeposit', async (request, response) => {
  const body = request.body

  const token = getTokenFrom(request)
  const decodedToken = jwt.verify(token, process.env.SECRET)
  if (!token || !decodedToken.cardId) {
    return response.status(401).json({ error: 'token missing or invalid' })
  }
  const filter = { cardId: decodedToken.cardId };
  const update = { $inc: { "creditBalance": body.amount }, $push: { creditTransactions: { time: new Date().toUTCString(), amount: "+" + body.amount } } }

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
    .then(updatedCard => {
      response.json(updatedCard.toJSON())
    })
    .catch(error => console.log(error))
})

cardsRouter.put('/banktransfer', async (request, response) => {
  const body = request.body

  const token = getTokenFrom(request)
  const decodedToken = jwt.verify(token, process.env.SECRET)
  if (!token || !decodedToken.cardId) {
    return response.status(401).json({ error: 'token missing or invalid' })
  }

  let filter = { cardId: decodedToken.cardId };
  let update = { $inc: { "debitBalance": -body.amount }, $push: { debitTransactions: { time: new Date().toUTCString(), amount: "-" + body.amount } } }

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
  .catch(error => console.log(error))

  filter = { cardId: body.receiverId };
  update = { $inc: { "debitBalance": body.amount }, $push: { debitTransactions: { time: new Date().toUTCString(), amount: "+" + body.amount } } }

  await Card.findOneAndUpdate(filter, update, {
    new: true
  })
  .then(updatedCard => {
    response.json(updatedCard.toJSON())
  })
  .catch(error => console.log(error))

})

module.exports = cardsRouter