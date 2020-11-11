const mongoose = require('mongoose')
const uniqueValidator = require('mongoose-unique-validator')

const cardSchema = new mongoose.Schema({
  cardId: {
    type: Number,
    minlength: 4,
    required: true,
    unique: true
  },
  owner: {
    type: String,
    required: true
  },
  pin: {
    type: Number,
    required: true
  },
  debitBalance: {
    type: Number,
    required: true
  },
  creditBalance: {
    type: Number,
    required: true
  },
  creditLimit: {
    type: Number,
    required: true
  },
  debitTransactions: {
    type: Array,
    required: true
  },
  creditTransactions: {
    type: Array,
    required: true
  }
})

cardSchema.set('toJSON', {
  transform: (document, returnedObject) => {
    returnedObject.id = returnedObject._id.toString()
    delete returnedObject._id
    delete returnedObject.__v
    delete returnedObject.passwordHash
  }
})

module.exports = mongoose.model('Card', cardSchema)