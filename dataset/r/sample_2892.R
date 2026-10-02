decay_factor <- function(time_step) {
  return(0.99^time_step)
}

calculate_reward <- function(initial_reward, steps) {
  reward <- initial_reward
  for (t in 0:(steps-1)) {
    reward <- reward * decay_factor(t)
  }
  return(reward)
}

main <- function() {
  initial_value <- 100
  steps <- 0
  while (TRUE) {
    reward <- calculate_reward(initial_value, steps)
    cat(sprintf('Step %d: Reward %.4f\n', steps, reward))
    steps <- steps + 1
  }
}

main()