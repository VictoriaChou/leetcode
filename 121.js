/*
买卖股票的最佳时机
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
注意：你不能在买入股票前卖出股票。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
testcases:
input: [7,1,5,3,6,4]
output: 5
input: [7,6,4,3,1]
output: 0
**/
// solution1: 单调栈
// 时间复杂度: O(n)，对n个元素pop和push
var maxProfit_s1 = function(prices) {
  let ans = 0
  let st = []
  prices.push(-1)
  for(let i=0; i<prices.length; i++) {
    while(st.length !== 0 && st[st.length - 1] > prices[i]) {
      ans = Math.max((st[st.length - 1] - st[0]), ans)
      console.log('st pop', st)
      st.pop()
    }
    console.log('st push', st)
    st.push(prices[i])
  }
  return ans
}

// solution2: 一次遍历
// 时间复杂度: O(n)

var maxProfit_s2 = function(prices) {
  let ans = 0
  let min = Number.MAX_SAFE_INTEGER
  for(let i=0; i<prices.length; i++) {
    if(prices[i] < min) {
      min = prices[i]
    } else {
      ans = Math.max(ans, prices[i] - min)
    }
  }
  return ans
}