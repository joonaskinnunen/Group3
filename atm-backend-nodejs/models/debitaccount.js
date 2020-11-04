const mongoose = require('mongoose')

const debitAccountSchema = new mongoose.Schema({
    balance: {
        type: Number,
        required: true
    },
    transactions: []
})

debitAccountSchema.set('toJSON', {
    transform: (document, returnedObject) => {
        returnedObject.id = returnedObject._id.toString()
        delete returnedObject._id
        delete returnedObject.__v
    }
})

module.exports = mongoose.model('DebitAccount', debitAccountSchema)