/**
 * @param {number[][]} graph
 * @return {boolean}
 */
// [[1,3], [0,2], [1,3], [0,2]]

function isBipartite(graph) {
  const len = graph.length
  let color = []
  let COLOR = {
    UNCOLORED: 0,
    RED: 1,
    GREEN: 2
  }
  let valid = true
  for (let i = 0; i < len; i++) {
    color[i] = COLOR.UNCOLORED
  }
  // 无向图不保证连通
  for (let i = 0; i < len && valid; i++) {
    if (color[i] === COLOR.UNCOLORED) {
      dfs(i, COLOR.RED, graph)
    }
  }

  function dfs(node, c, graph) {
    color[node] = c
    let cNei = (c === COLOR.RED) ? COLOR.GREEN : COLOR.RED
    for (let nei of graph[node]) {
      if (color[nei] === COLOR.UNCOLORED) {
        dfs(nei, cNei, graph)
        if (!valid) return
      } else if (color[nei] !== cNei) {
        valid = false
        return
      }
    }
  }
  dfs(0, COLOR.RED, graph)
  return valid
};
