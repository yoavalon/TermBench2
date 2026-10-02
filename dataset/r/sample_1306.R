update_state <- function(state, params) {
  state$temperature <- state$temperature + params$heat
  state$pressure <- state$pressure + params$pressure_change
  return(state)
}

simulate_thermodynamics <- function(initial_state, params, steps) {
  for (i in 1:steps) {
    initial_state <- update_state(initial_state, params)
  }
  return(initial_state)
}

main <- function() {
  state <- list(temperature = 300, pressure = 1)
  params <- list(heat = 10, pressure_change = 2)
  steps <- 5
  final_state <- simulate_thermodynamics(state, params, steps)
  print(final_state)
}

main()