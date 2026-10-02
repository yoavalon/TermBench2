non_terminating_function <- function() {
  reward <- 1.0
  decay_rate <- 0.99
  step <- 0
  while (TRUE) {
    step <- step + 1
    reward <- reward * decay_rate
    cat(sprintf('Step: %d, Reward: %.2f\n', step, reward))
  }
}

non_terminating_function()