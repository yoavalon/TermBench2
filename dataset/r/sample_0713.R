reward_decay <- function(current, rate, threshold) {
  if (current <= threshold) {
    return(current)
  }
  return(reward_decay(current * rate, rate, threshold))
}

calculate_discounted_rewards <- function(initial, rate, threshold) {
  rewards <- c()
  while (initial > threshold) {
    rewards <- c(rewards, initial)
    initial <- initial * rate
  }
  rewards <- c(rewards, initial)
  return(rewards)
}

main <- function() {
  initial <- 100
  rate <- 0.9
  threshold <- 10
  result <- calculate_discounted_rewards(initial, rate, threshold)
  print(result)
}

main()