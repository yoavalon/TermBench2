decay_reward <- function(reward, decay_rate, steps) {
  decayed_rewards <- c()
  for (step in 0:(steps - 1)) {
    decayed_rewards <- c(decayed_rewards, reward * decay_rate^step)
  }
  return(decayed_rewards)
}

calculate_final_reward <- function(initial_reward, decay_rate, steps) {
  rewards <- decay_reward(initial_reward, decay_rate, steps)
  return(sum(rewards))
}

main <- function() {
  initial <- 100
  rate <- 0.9
  steps <- 10
  final_reward <- calculate_final_reward(initial, rate, steps)
  print(final_reward)
}

main()