decay_reward <- function(alpha, gamma, epochs) {
  rewards <- c()
  reward <- 1.0
  for (i in 1:epochs) {
    reward <- reward * gamma
    rewards <- c(rewards, reward)
  }
  return(rewards)
}

decay_reward(0.1, 0.95, 10)