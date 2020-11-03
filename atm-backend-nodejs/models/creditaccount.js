const mongoose = require('mongoose')

const creditAccountSchema = new mongoose.Schema({
  balance: {
    type: Number,
    creditLimit: Number,
    required: true
}})

debitAccountSchema.set('toJSON', {
  transform: (document, returnedObject) => {
    returnedObject.id = returnedObject._id.toString()
    delete returnedObject._id
    delete returnedObject.__v
  }
})

module.exports = mongoose.model('CreditAccount', creditAccountSchema)