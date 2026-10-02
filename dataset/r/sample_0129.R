update_state <- function(state, params) {
  for (key in names(params)) {
    state[[key]] <- state[[key]] + params[[key]]
  }
  return(state)
}

check_stability <- function(state, thresholds) {
  for (key in names(thresholds)) {
    if (abs(state[[key]]) > thresholds[[key]]) {
      return(FALSE)
    }
  }
  return(TRUE)
}

simulate <- function(state, params, thresholds, steps) {
  for (i in 1:steps) {
    state <- update_state(state, params)
    if (!check_stability(state, thresholds)) {
      return(state)
    }
  }
  return(state)
}

main <- function() {
  state <- list(temp = 0, pressure = 0)
  params <- list(temp = 0.1, pressure = -0.05)
  thresholds <- list(temp = 1, pressure = 0.5)
  steps <- 100
  final_state <- simulate(state, params, thresholds, steps)
  print(final_state)
}

main()