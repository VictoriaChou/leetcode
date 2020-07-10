function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}
var resur = function(nums, left, right) {
  if(left > right) {
      return null
  }
  const mid = Math.floor((left + right) / 2)
  const root = new TreeNode(nums[mid])
  console.log('root', root)
  root.left = resur(nums, left, mid - 1)
  root.right = resur(nums, mid + 1, right)
  return root
}
var sortedArrayToBST = function(nums) {
  return resur(nums, 0, nums.length - 1)
};
console.log(sortedArrayToBST([-10,-3,0,5,9]))