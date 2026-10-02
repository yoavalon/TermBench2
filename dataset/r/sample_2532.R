decay_reward <- function(reward, decay_rate) {
  return(reward * decay_rate)
}

simulate_reward_decay <- function(initial_reward, decay_rate, steps) {
  rewards <- c()
  current_reward <- initial_reward
  for (i in 1:steps) {
    rewards <- c(rewards, current_reward)
    current_reward <- decay_reward(current_reward, decay_rate)
  }
  return(rewards)
}

main <- function() {
  initial_reward <- 100.0
  decay_rate <- 0.95
  steps <- 10
  rewards <- simulate_reward_decay(initial_reward, decay_rate, steps)
  for (step in 1:length(rewards)) {
    cat(sprintf("Step %d: Reward %.2f\n", step, rewards[step]))
  }
}

main()