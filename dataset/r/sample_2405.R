reward_decay <- function(alpha, gamma, steps) {
  reward <- 1
  for (i in 1:steps) {
    reward <- reward * alpha * gamma
  }
  return(reward)
}

alpha <- 0.5
gamma <- 0.9
steps <- 10
result <- reward_decay(alpha, gamma, steps)
print(result)