reward_decay <- function(reward, decay_rate, steps) {
  decayed_rewards <- c()
  for (i in 1:steps) {
    decayed_rewards <- c(decayed_rewards, reward)
    reward <- reward * decay_rate
  }
  return(decayed_rewards)
}

process_data <- function(data) {
  results <- list()
  for (idx in seq_along(data)) {
    results[[idx]] <- data[idx]
  }
  return(results)
}

main <- function() {
  initial_reward <- 1.0
  decay_rate <- 0.9
  steps <- 10
  rewards <- reward_decay(initial_reward, decay_rate, steps)
  output <- process_data(rewards)
  for (key in seq_along(output)) {
    cat(sprintf('Step %d: %f\n', key - 1, output[[key]]))
  }
}

main()