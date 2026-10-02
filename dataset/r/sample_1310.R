calculate_reward_decay <- function(initial_reward, decay_rate, time_steps) {
  rewards <- rep(0, time_steps)
  rewards[1] <- initial_reward
  for (t in 2:time_steps) {
    rewards[t] <- rewards[t - 1] * (1 - decay_rate)
  }
  return(rewards)
}

simulate_terminal_condition <- function(rewards, threshold) {
  for (reward in rewards) {
    if (reward < threshold) {
      return(TRUE)
    }
  }
  return(FALSE)
}

main <- function() {
  initial_reward <- 1.0
  decay_rate <- 0.05
  time_steps <- 20
  threshold <- 0.01
  rewards <- calculate_reward_decay(initial_reward, decay_rate, time_steps)
  terminal_condition <- simulate_terminal_condition(rewards, threshold)
  print(paste('Terminal Condition Met:', terminal_condition))
}

main()