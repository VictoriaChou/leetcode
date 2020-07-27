/**
 * https://leetcode-cn.com/problems/dungeon-game
 * solution: 反向动态规划，正向动态规划不具备【无后效性】，
 * 既需要保证从出发点到当前点路径的和最大
 * 又需要考虑初始值最小
 * 使用反向动态规划，不需要考虑当前路径和，只需要保证初始值最小即可
 * @param {*} dungeon 
 * @return {number}
 */
var calculateMinimumHP = function (dungeon) {
  let M = dungeon.length
  let N = dungeon[0].length
  let dp = []
  for (let i = 0; i < M; i++) {
    dp[i] = []
    for (let j = 0; j < N; j++) {
      dp[i].push(0)
    }
  }
  for (let i = M - 1; i >= 0; i--) {
    for (let j = N - 1; j >= 0; j--) {
      if (i === M - 1 && j === N - 1) {
        dp[i][j] = Math.max(-(dungeon[i][j] - 1), 1)
      } else if (i === M - 1) {
        dp[i][j] = Math.max(dp[i][j + 1] - dungeon[i][j], 1)
      } else if (j === N - 1) {
        dp[i][j] = Math.max(dp[i + 1][j] - dungeon[i][j], 1)
      } else {
        dp[i][j] = Math.max(Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1)
      }
    }
  }
  return dp[0][0]
}