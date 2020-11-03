const mongoose = require('mongoose')

const cardSchema = new mongoose.Schema({
  cardId: {
    type: String,
    minlength: 4,
    required: true
  },
  owner: {
    type: String,
    required: true
  },
  pin: {
    type: Number,
    required: true
  },
  debitAccountId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'DebitAccount',
    required: true
  },
  creditAccountId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'CreditAccount'
  }
})

cardSchema.set('toJSON', {
  transform: (document, returnedObject) => {
    returnedObject.id = returnedObject._id.toString()
    delete returnedObject._id
    delete returnedObject.__v
  }
})

module.exports = mongoose.model('Card', cardSchema)