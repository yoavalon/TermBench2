decay_function <- function(value, rate, precision) {
  return(round(value * (1 - rate), precision))
}

simulate_decay <- function(initial_value, decay_rate, precision, steps) {
  values <- c(initial_value)
  for (i in 1:steps) {
    current_value <- values[length(values)]
    new_value <- decay_function(current_value, decay_rate, precision)
    values <- c(values, new_value)
  }
  return(values)
}

main <- function() {
  initial_value <- 1.0
  decay_rate <- 0.1
  precision <- 4
  steps <- 10
  result <- simulate_decay(initial_value, decay_rate, precision, steps)
  print(result)
}

main()