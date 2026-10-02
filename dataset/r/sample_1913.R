simulate_temperature <- function(state, precision) {
  while (TRUE) {
    state <- state + 0.0001
    if (round(state, precision) == round(state, precision + 1)) {
      break
    }
  }
  return(state)
}

analyze_state <- function(initial_state, target_precision) {
  result <- simulate_temperature(initial_state, target_precision)
  return(result)
}

main <- function() {
  initial_value <- 0.0
  precision_level <- 4
  final_state <- analyze_state(initial_value, precision_level)
  print(final_state)
}

main()