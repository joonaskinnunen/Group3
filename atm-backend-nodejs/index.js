const express = require('express')
const app = express()

let testjson = [
  {
      name: "Joonas",
      id: 1
  }
]

app.get('/', (req, res) => {
  res.send('<h1>Hello World!</h1>')
})

app.get('/api/testroute', (req, res) => {
  res.json(testjson)
})

const PORT = 3001
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`)
})