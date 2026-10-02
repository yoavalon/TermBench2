decay_reward <- function(reward, decay_rate, steps) {
  rewards <- numeric(steps)
  rewards[1] <- reward
  for (i in 2:steps) {
    rewards[i] <- rewards[i - 1] * decay_rate
  }
  return(rewards)
}

main <- function() {
  initial_reward <- 100
  decay_rate <- 0.95
  steps <- 10
  rewards <- decay_reward(initial_reward, decay_rate, steps)
  print(rewards)
}

main()