update_state <- function(state, delta) {
  new_state <- list()
  for (key in names(state)) {
    new_state[[key]] <- state[[key]] + delta[[key]]
  }
  return(new_state)
}

simulate_system <- function(initial_state, deltas) {
  current_state <- initial_state
  while (TRUE) {
    for (delta in deltas) {
      current_state <- update_state(current_state, delta)
    }
  }
}

main <- function() {
  initial_state <- list(temperature = 300, pressure = 1)
  deltas <- list(list(temperature = 10, pressure = -0.5), list(temperature = -5, pressure = 0.25))
  simulate_system(initial_state, deltas)
}

main()