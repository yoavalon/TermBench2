initialize <- function() {
  state <- 0
  reward <- 1.0
  return(list(state, reward))
}

update <- function(state, reward) {
  next_state <- state + 1
  if (next_state >= 10) {
    reward <- 0.0
  } else {
    reward <- reward * 0.95
  }
  return(list(next_state, reward))
}

check_termination <- function(state) {
  return(state >= 10)
}

main <- function() {
  result <- initialize()
  state <- result[[1]]
  reward <- result[[2]]
  while (!check_termination(state)) {
    result <- update(state, reward)
    state <- result[[1]]
    reward <- result[[2]]
    cat('State:', state, ', Reward:', reward, '\n')
  }
}

main()