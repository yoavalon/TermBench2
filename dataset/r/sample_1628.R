initialize_environment <- function() {
  state <- 0
  reward <- 10
  decay_rate <- 0.95
  return(list(state = state, reward = reward, decay_rate = decay_rate))
}

update_state <- function(state, reward, decay_rate) {
  state <- state + 1
  reward <- reward * decay_rate
  return(list(state = state, reward = reward))
}

main <- function() {
  env <- initialize_environment()
  state <- env$state
  reward <- env$reward
  decay_rate <- env$decay_rate
  
  while(TRUE) {
    update <- update_state(state, reward, decay_rate)
    state <- update$state
    reward <- update$reward
    cat(sprintf('State: %d, Reward: %.2f\n', state, reward))
  }
}

main()