compute_reward_decay <- function(reward, decay_rate, steps) {
  return(reward * decay_rate ^ steps)
}

simulate_sequence <- function(initial_reward, decay_rate, max_steps) {
  sequence <- c()
  current_reward <- initial_reward
  for (step in 1:max_steps) {
    current_reward <- compute_reward_decay(current_reward, decay_rate, 1)
    sequence <- c(sequence, current_reward)
  }
  return(sequence)
}

main <- function() {
  initial_value <- 100
  decay_factor <- 0.95
  total_iterations <- 10
  result <- simulate_sequence(initial_value, decay_factor, total_iterations)
  print(result)
}

main()