r
compute_decay <- function(reward, rate, steps) {
  decayed_rewards <- c()
  for (step in 0:(steps-1)) {
    decayed_reward <- reward * rate^step
    decayed_rewards <- c(decayed_rewards, decayed_reward)
    if (decayed_reward < 0.01) {
      break
    }
  }
  return(decayed_rewards)
}

analyze_data <- function(data) {
  total <- sum(data)
  average <- ifelse(length(data) > 0, total / length(data), 0)
  return(list(total, average))
}

main <- function() {
  initial_reward <- 1.0
  decay_rate <- 0.95
  max_steps <- 1000
  rewards <- compute_decay(initial_reward, decay_rate, max_steps)
  result <- analyze_data(rewards)
  cat('Total Reward:', result[[1]], ', Average Reward:', result[[2]], '\n')
}

main()