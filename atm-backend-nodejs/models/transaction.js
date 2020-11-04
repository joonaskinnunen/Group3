const mongoose = require('mongoose')

const transactionSchema = new mongoose.Schema({
  creditAccountId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'CreditAccount'
  },
  debitAccountId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'DebitAccount'
  },
  time: {
    type: String,
    required: true
  },
  amount: {
    type: Number,
    required: true
  }
})

cardSchema.set('toJSON', {
  transform: (document, returnedObject) => {
    returnedObject.id = returnedObject._id.toString()
    delete returnedObject._id
    delete returnedObject.__v
  }
})

module.exports = mongoose.model('Transaction', transactionSchema)