// 用来读题目的输入
const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let inputArr = []
rl.on('line', function (input) {
  inputArr.push(input)
})

rl.on('close', function () {

})