reward_decay <- function(init_val, decay_rate, steps) {
  rewards <- c()
  current_val <- init_val
  for (i in 1:steps) {
    rewards <- c(rewards, current_val)
    current_val <- current_val * decay_rate
  }
  return(rewards)
}

analyze_rewards <- function(rewards) {
  total <- sum(rewards)
  avg <- total / length(rewards)
  return(c(total, avg))
}

main <- function() {
  initial_value <- 1.0
  decay_rate <- 0.9
  number_of_steps <- 10
  sequence <- reward_decay(initial_value, decay_rate, number_of_steps)
  total <- analyze_rewards(sequence)[1]
  average <- analyze_rewards(sequence)[2]
  cat('Total:', total, ', Average:', average, '\n')
}

main()