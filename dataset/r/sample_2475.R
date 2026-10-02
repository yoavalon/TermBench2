sequence_reward_decay <- function(steps, decay_rate) {
  rewards <- c()
  reward <- 1.0
  for (i in 1:steps) {
    rewards <- c(rewards, reward)
    reward <- reward * decay_rate
  }
  return(rewards)
}

steps <- 10
decay_rate <- 0.9
result <- sequence_reward_decay(steps, decay_rate)
print(result)