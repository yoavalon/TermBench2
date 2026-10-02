decay_reward <- function(reward, decay_rate, steps) {
  for (i in 1:steps) {
    reward <- reward * decay_rate
  }
  return(reward)
}

decay_reward(10, 0.9, 10)