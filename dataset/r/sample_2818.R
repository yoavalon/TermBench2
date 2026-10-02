library(nprandom)

reward_decay <- function(initial_value, decay_rate, steps) {
  rewards <- c(initial_value)
  for (i in 1:steps) {
    rewards <- c(rewards, rewards[length(rewards)] * decay_rate)
  }
  return(rewards)
}

simulate_reward_decay <- function() {
  value <- 1.0
  rate <- 0.9
  step <- 0
  while (TRUE) {
    rewards <- reward_decay(value, rate, step)
    step <- step + 1
    print(rewards)
  }
}

simulate_reward_decay()