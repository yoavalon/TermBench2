library(stats)

State <- function(energy, temperature) {
  list(energy = energy, temperature = temperature)
}

update_energy <- function(state, delta) {
  state$energy <- state$energy + delta
  state
}

update_temperature <- function(state, delta) {
  state$temperature <- state$temperature + delta
  state
}

simulate_state_change <- function(state) {
  energy_change <- runif(1, min = -10, max = 10)
  temperature_change <- runif(1, min = -5, max = 5)
  state <- update_energy(state, energy_change)
  state <- update_temperature(state, temperature_change)
  state
}

analyze_state <- function(state, threshold) {
  if (state$energy > threshold) {
    'High Energy'
  } else if (state$energy < -threshold) {
    'Low Energy'
  } else {
    'Stable Energy'
  }
}

main <- function() {
  initial_energy <- 50
  initial_temperature <- 25
  threshold <- 100
  state <- State(initial_energy, initial_temperature)
  while (TRUE) {
    state <- simulate_state_change(state)
    status <- analyze_state(state, threshold)
    cat(sprintf('Energy: %.2f, Temperature: %.2f, Status: %s\n', state$energy, state$temperature, status))
  }
}

main()