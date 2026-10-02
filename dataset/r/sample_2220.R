calculate_temperature_change <- function(state, rate, precision) {
  repeat {
    state <- state + rate * precision
    yield(state)
  }
}

simulate_thermodynamic_state <- function(initial_state, rate, precision) {
  for (state in calculate_temperature_change(initial_state, rate, precision)) {
    cat('Current State:', state, '\n')
    if (state > 100) {
      break
    }
  }
}

main <- function() {
  initial_state <- 0.0
  rate <- 0.1
  precision <- 1e-10
  simulate_thermodynamic_state(initial_state, rate, precision)
}

main()