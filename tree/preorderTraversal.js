// 前序遍历二叉树

// 递归
const resur = function(root, res) {
  if(root === null) return
  console.log(res)
  res.push(root.val)
  resur(root.left, res)
  resur(root.right, res)
}
var preorderTraversal = function(root) {
  let res = []
  resur(root, res)
  return res
};

// 迭代

var preorderTraversal = function(root) {
  if(root === null) return []
  let res = []
  let stack = [root]
  while (stack.length > 0) {
      let cur = stack.pop()
      res.push(cur.val)
      if(cur.right){
          stack.push(cur.right)
      }
      if(cur.left) {
          stack.push(cur.left)
      }
  }
  return res
};