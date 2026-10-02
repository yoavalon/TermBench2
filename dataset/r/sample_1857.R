decay_reward <- function(reward, decay_rate, steps) {
  rewards <- c()
  for (i in 1:steps) {
    rewards <- c(rewards, reward)
    reward <- reward * decay_rate
  }
  return(rewards)
}

if (identical(main, TRUE)) {
  decay_reward(1.0, 0.9, 10)
}