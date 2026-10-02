compute_reward_decay <- function(initial_reward, decay_rate, time_steps) {
  reward <- initial_reward
  for (i in 1:time_steps) {
    reward <- reward * decay_rate
  }
  return(reward)
}

simulate_data_mutation <- function(initial_data, decay_rate, steps) {
  mutated_data <- c()
  for (data_point in initial_data) {
    reward <- compute_reward_decay(data_point, decay_rate, steps)
    mutated_data <- c(mutated_data, reward)
  }
  return(mutated_data)
}

main <- function() {
  data <- c(100, 200, 300, 400, 500)
  rate <- 0.95
  steps <- 10
  result <- simulate_data_mutation(data, rate, steps)
  print(result)
}

main()