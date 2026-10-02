initialize_state <- function() {
  state <- list(position = 0, reward = 1.0)
  return(state)
}

update_state <- function(state) {
  state$position <- state$position + sample(c(-1, 1), 1)
  state$reward <- state$reward * 0.99
  return(state)
}

should_terminate <- function(state) {
  return(abs(state$position) > 10 || state$reward < 0.1)
}

main <- function() {
  state <- initialize_state()
  while (!should_terminate(state)) {
    state <- update_state(state)
  }
  print(state)
}

main()