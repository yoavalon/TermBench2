simulate_decay <- function(steps, decay_rate) {
  reward <- 1.0
  rewards <- c()
  for (i in 1:steps) {
    rewards <- c(rewards, reward)
    reward <- reward * decay_rate
  }
  return(rewards)
}

main <- function() {
  print(simulate_decay(10, 0.9))
}

main()