decay_reward <- function(reward, decay_rate, steps) {
  return(reward * decay_rate ^ steps)
}

calculate_total_reward <- function(initial_reward, decay_rate, max_steps) {
  total_reward <- 0
  for (step in 0:(max_steps - 1)) {
    total_reward <- total_reward + decay_reward(initial_reward, decay_rate, step)
  }
  return(total_reward)
}

main <- function() {
  initial_reward <- 100.0
  decay_rate <- 0.95
  max_steps <- 1000
  total_reward <- calculate_total_reward(initial_reward, decay_rate, max_steps)
  print(total_reward)
}

main()