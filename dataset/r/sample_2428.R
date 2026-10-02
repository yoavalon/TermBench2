reward_decay <- function() {
  reward <- 1.0
  decay_rate <- 0.9
  iterations <- 10
  for (i in 1:iterations) {
    reward <- reward * decay_rate
  }
  return(reward)
}
reward_decay()