function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}
var recure = function(tree) {
    if(tree === null) return 0
    left = recure(tree.left)
    if(left === -1) return -1
    right = recure(tree.right)
    if(right === -1) return -1
    console.log(Math.abs(left - right))
    return Math.abs(left - right) <= 1 ? Math.max(left, right) + 1  : -1
}
var isBalanced = function(root) {
    console.log(recure(root))
    return recure(root) !== -1
};
isBalanced()