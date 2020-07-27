var countSmaller = function(nums) {
  let count = []
  for(let i=0; i<nums.length; i++) {
      count[i] = 0
      for(let j=i; j<nums.length; j++) {
          if(nums[j] < nums[i]) {
              count[i] += 1
          }
      }
  }
  return count
};
countSmaller([5,2,6,1])