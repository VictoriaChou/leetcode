/*
63. 不同路径 II
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
testcases:
input: [
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
output: 2
**/

var uniquePathsWithObstacles = function(obstacleGrid) {
  let m = obstacleGrid.length
  let n = obstacleGrid[0].length

  let status = new Int8Array(n)
  if(obstacleGrid[0][0] === 0) {
    status[0] = 1
  }

  for(let i=0; i<m; i++) {
      for(let j=0; j<n; j++) {
          if(obstacleGrid[i][j] === 1) {
              status[j] = 0
              continue
          }
          if(j - 1 >= 0 && obstacleGrid[i][j-1] == 0) {
            console.log(j, status[j])
            status[j] += status[j - 1]
          }
      }
  }
  return status[status.length - 1]
};