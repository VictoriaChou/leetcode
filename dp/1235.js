var jobScheduling = function(startTime, endTime, profit) {
  const len = startTime.length
  let tasks = []
  for(let i=0; i<len; i++) {
    tasks[i] = {
      startTime: startTime[i],
      endTime: endTime[i],
      profit: profit[i]
    }
  }
  tasks.sort((a, b) => a.endTime - b.endTime)
  console.log(tasks)
  let opt = []
  opt[0] = tasks[0].profit
  for(let i=1; i<len; i++) {
    let prev = undefined
      for(let j=i-1; j>=0; j--) {
          if(tasks[j].endTime <= tasks[i].startTime) {
            prev = j
            break
          }
      }
      console.log(prev, opt)
      opt[i] = Math.max(opt[i-1], tasks[i].profit + (prev!==undefined ? opt[prev]:0))
  }
  return opt[len-1]
};
jobScheduling([15,44,15,47,11,18,5,41,38,25,19,25],
  [33,48,20,49,37,22,32,48,39,37,38,40],
  [18,19,16,1,5,12,17,7,19,9,18,9])