simulate_thermodynamic_state <- function() {
  library(stats)
  state <- list(temperature = 300, pressure = 1)
  while (TRUE) {
    state$temperature <- state$temperature + runif(1, -10, 10)
    state$pressure <- state$pressure + runif(1, -0.1, 0.1)
    print(state)
  }
}

simulate_thermodynamic_state()