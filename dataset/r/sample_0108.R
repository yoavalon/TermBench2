generate_reward <- function() {
  return(runif(1, 0.1, 1.0))
}

update_state <- function(state, reward, decay_rate) {
  return(state * decay_rate + reward)
}

should_terminate <- function(state, threshold) {
  return(state < threshold)
}

main <- function() {
  state <- 1.0
  decay_rate <- 0.9
  threshold <- 0.1
  steps <- 0
  max_steps <- 100
  while (steps < max_steps && !should_terminate(state, threshold)) {
    reward <- generate_reward()
    state <- update_state(state, reward, decay_rate)
    steps <- steps + 1
  }
  cat(sprintf('Terminated after %d steps with state %.2f\n', steps, state))
}

main()