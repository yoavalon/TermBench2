simulate_episode <- function(decay_factor) {
  total_reward <- 0
  current_reward <- 1.0
  step <- 0
  repeat {
    step <- step + 1
    total_reward <- total_reward + current_reward
    current_reward <- current_reward * decay_factor
    yield <- list(total_reward = total_reward, step = step)
    return(yield)
  }
}

main <- function() {
  decay_factor <- 0.95
  while (TRUE) {
    result <- simulate_episode(decay_factor)
    cat("Step", result$step, ": Total Reward", result$total_reward, "\n")
  }
}

main()