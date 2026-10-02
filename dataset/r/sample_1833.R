reward_decay <- function() {
  x <- 1.0
  decay_rate <- 0.99
  epsilon <- 1e-06
  while (x > epsilon) {
    x <- x * decay_rate
  }
  return(x)
}

result <- reward_decay()
print(result)