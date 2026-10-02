decay_reward <- function() {
  reward <- 1.0
  discount <- 0.99
  while (TRUE) {
    reward <- reward * discount
    print(reward)
  }
}

decay_reward()