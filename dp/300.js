/**
 * Longest ascending subsequence
 * @param {number[]} nums
 * @return {number}
 */
// Method1: dp
// 时间复杂度O(N^2)
var lengthOfLIS = function (nums) {
    if (nums.length === 0) return 0
    let dp = []
    for (let i = 0; i < nums.length; i++) {
        let maxdp = 1
        for (let j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                maxdp = Math.max(maxdp, dp[j] + 1)
            }
        }
        dp[i] = maxdp
    }
    return Math.max(...dp)
};

// Method2: dp + greedy + dichotomy
var lengthOfLIS2 = function (nums) {
    if (nums.length === 0) return 0
    let tail = [nums[0]]
    for (let i = 0; i < nums.length; i++) {
        const len = tail.length
        if (nums[i] > tail[len - 1]) {
            tail[len] = nums[i]
        } else {
            let left = 0
            let right = len
            while (left < right) {
                let mid = left + ((right - left) >>> 1)
                if (tail[mid] < nums[i]) {
                    left = mid + 1
                } else {
                    right = mid
                }
            }
            tail[left] = nums[i]
        }
    }
    console.log(tail)
    return tail.length
}
lengthOfLIS2([4, 10, 4, 3, 8, 9])