simulate_decay_reward <- function(initial_reward, decay_rate, steps) {
  rewards <- c(initial_reward)
  for (i in 1:steps) {
    current_reward <- rewards[length(rewards)] * (1 - decay_rate)
    rewards <- c(rewards, current_reward)
  }
  return(rewards)
}

main <- function() {
  initial_reward <- 1.0
  decay_rate <- 0.1
  steps <- 10
  result <- simulate_decay_reward(initial_reward, decay_rate, steps)
  print(result)
}

main()