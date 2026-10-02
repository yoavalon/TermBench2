simulate_reward_decay <- function(steps, decay_rate) {
  rewards <- c(runif(1))
  for (i in 2:steps) {
    rewards[i] <- rewards[i - 1] * decay_rate
  }
  return(rewards)
}

main <- function() {
  steps <- 10
  decay_rate <- 0.9
  result <- simulate_reward_decay(steps, decay_rate)
  print(result)
}

main()