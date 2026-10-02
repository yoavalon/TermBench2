simulate_decay <- function(steps) {
  reward <- 1.0
  decay_rate <- 0.99
  for (i in 1:steps) {
    reward <- reward * decay_rate
  }
  return(reward)
}

result <- simulate_decay(1000)
print(result)