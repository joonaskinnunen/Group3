const cardsRouter = require('express').Router()
const Card = require('../models/card')
require('dotenv').config()

const isAuthorized = (req) => {
  const password = req.get('Password')
  const username = req.get('Username')

  if (process.env.PASSWORD == password && process.env.USERNAME == username) return true
  return false
}

cardsRouter.get('/', async (request, response) => {
  const cards = await Card.find({})
  if (isAuthorized(request)) {
    response.json(cards.map(card => card.toJSON()))
  }
  response.status(400).send('Not authorized')

})

cardsRouter.get('/:id', async (request, response) => {
  const card = await Card.findById(request.params.id)
  if (isAuthorized(request)) {
    if (card) {
      response.json(card.toJSON())
    } else {
      response.status(404).end()
    }
  } else {
    response.status(400).send('Not authorized')
  }
})

cardsRouter.post('/', async (request, response) => {
  const body = request.body

  if (isAuthorized(request)) {
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
  }
  response.status(400).send('Not authorized')
})
cardsRouter.put('/debitwithdrawal/:id', async (request, response) => {
  const body = request.body

  if (isAuthorized(request)) {

    const filter = { cardId: request.params.id };
    const update = { $inc: { "debitBalance": -body.amount } };

    await Card.findOneAndUpdate(filter, update, {
      new: true
    })
      .then(updatedCard => {
        response.json(updatedCard.toJSON())
      })
      .catch(error => console.log(error))
  } else {
    response.status(400).send('Not authorized')
  }
})

cardsRouter.put('/creditwithdrawal/:id', async (request, response) => {
  const body = request.body

  if (isAuthorized(request)) {
    const filter = { cardId: request.params.id };
    const update = { $inc: { "creditBalance": -body.amount } };

    await Card.findOneAndUpdate(filter, update, {
      new: true
    })
      .then(updatedCard => {
        response.json(updatedCard.toJSON())
      })
      .catch(error => console.log(error))
  }
  response.status(400).send('Not authorized')
})

cardsRouter.put('/debitdeposit/:id', async (request, response) => {
  const body = request.body

  if (isAuthorized(request)) {
    const filter = { cardId: request.params.id };
    const update = { $inc: { "debitBalance": body.amount } };

    let card = await Card.findOneAndUpdate(filter, update, {
      new: true
    })
      .then(updatedCard => {
        response.json(updatedCard.toJSON())
      })
      .catch(error => console.log(error))
  }
  response.status(400).send('Not authorized')
})

cardsRouter.put('/creditdeposit/:id', async (request, response) => {
  const body = request.body

  if (isAuthorized(request)) {
    const filter = { cardId: request.params.id };
    const update = { $inc: { "creditBalance": body.amount } };

    await Card.findOneAndUpdate(filter, update, {
      new: true
    })
      .then(updatedCard => {
        response.json(updatedCard.toJSON())
      })
      .catch(error => console.log(error))
  }
  response.status(400).send('Not authorized')
})

cardsRouter.get('/:id', async (request, response) => {
  const card = await Card.findById(request.params.id)
  if (isAuthorized(request)) {
    if (card) {
      response.json(card.toJSON())
    } else {
      response.status(404).end()
    }
  }
  response.status(400).send('Not authorized')
})

module.exports = cardsRouter