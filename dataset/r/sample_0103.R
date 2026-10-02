compute_temperature_change <- function(initial_temp, final_temp, rate) {
  change <- (final_temp - initial_temp) * rate
  return(change)
}

update_state <- function(state, change) {
  state$temperature <- state$temperature + change
  state$energy <- state$energy + change * 1000
  return(state)
}

simulate_state <- function(initial_temp, final_temp, rate, steps) {
  state <- list(temperature = initial_temp, energy = 0)
  for (i in 1:steps) {
    change <- compute_temperature_change(state$temperature, final_temp, rate)
    state <- update_state(state, change)
  }
  return(state)
}

main <- function() {
  initial_temp <- 20
  final_temp <- 100
  rate <- 0.1
  steps <- 10
  result <- simulate_state(initial_temp, final_temp, rate, steps)
  print(result)
}

main()