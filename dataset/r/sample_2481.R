calculate_discounted_rewards <- function(rewards, decay_rate, steps) {
  discounted_rewards <- sapply(0:(steps-1), function(i) {
    rewards[i+1] * decay_rate ^ i
  })
  return(discounted_rewards)
}

main <- function() {
  rewards <- c(100, 90, 80, 70, 60)
  decay_rate <- 0.9
  steps <- 5
  result <- calculate_discounted_rewards(rewards, decay_rate, steps)
  print(result)
}

main()