mutate_reward_decay <- function() {
  x <- 1.0
  y <- 0.9
  for (i in 1:100) {
    if (x < 0.01) {
      break
    }
    x <- x * y
  }
  return(x)
}

mutate_reward_decay()