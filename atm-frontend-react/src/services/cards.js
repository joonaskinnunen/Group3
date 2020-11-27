import axios from "axios"
const baseUrl = "http://localhost:3001/api/cards"

let token = null

const setToken = newToken => {
  token = `bearer ${newToken}`
}

const getAll = () => {
    const request = axios.get(baseUrl)
    return request.then(response => response.data)
}

const debitWithdrawal = async amount => {
    const config = {
        headers: { Authorization: token },
    }
    console.log(amount)
      const response = await axios.put(`${baseUrl}/debitwithdrawal`, {"amount": amount}, config)
      console.log(response.data)
      return response.data
}

const creditWithdrawal = async amount => {
    const config = {
        headers: { Authorization: token },
    }
      const response = await axios.put(`${baseUrl}/creditwithdrawal`, amount, config)
      console.log(response.data)
      return response.data
}

const debitDeposit = async amount => {
    const config = {
        headers: { Authorization: token },
    }
    console.log(amount)
      const response = await axios.put(`${baseUrl}/debitdeposit`, {"amount": amount}, config)
      console.log(response.data)
      return response.data
}

const creditDeposit = async amount => {
    const config = {
        headers: { Authorization: token },
    }
      const response = await axios.put(`${baseUrl}/creditdeposit`, amount, config)
      console.log(response.data)
      return response.data
}

export default { getAll, debitWithdrawal, creditWithdrawal, debitDeposit, creditDeposit, setToken }