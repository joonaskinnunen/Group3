const jwt = require('jsonwebtoken')
const bcrypt = require('bcrypt')
const loginRouter = require('express').Router()
const Card = require('../models/card')
require('dotenv').config()

loginRouter.post('/', async (request, response) => {
  const body = request.body

  const card = await Card.findOne({ cardId: body.cardId })
  const passwordCorrect = card === null
    ? false
    : await bcrypt.compare(body.pin, card.pinHash)

  if (!(card && passwordCorrect)) {
    return response.status(401).json({
      error: 'invalid username or password'
    })
  }

  const cardForToken = {
    cardId: card.cardId,
  }

  const token = jwt.sign(cardForToken, process.env.SECRET)

  response
    .status(200)
    .send({ token, ...card._doc })
})

module.exports = loginRouter