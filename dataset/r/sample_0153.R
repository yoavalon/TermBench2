initialize_system <- function() {
  state <- list(temperature = 300, pressure = 1, energy = 500)
  return(state)
}

update_state <- function(state, time_step) {
  state$temperature <- state$temperature + 0.1 * time_step
  state$pressure <- state$pressure + 0.01 * time_step
  state$energy <- state$energy - 10 * time_step
  return(state)
}

check_termination <- function(state) {
  return(state$energy <= 0)
}

simulate <- function() {
  state <- initialize_system()
  time_step <- 1
  while (!check_termination(state)) {
    state <- update_state(state, time_step)
  }
  return(state)
}

main <- function() {
  final_state <- simulate()
  print(final_state)
}

main()