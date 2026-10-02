decay_reward <- function(initial_value, decay_rate, steps) {
  for (i in 1:steps) {
    initial_value <- initial_value * decay_rate
  }
  return(initial_value)
}

decay_reward(10.0, 0.9, 100)