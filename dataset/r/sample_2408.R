simulate_decay <- function(steps, decay_rate, initial_value) {
  value <- initial_value
  results <- c()
  for (i in 1:steps) {
    results <- c(results, value)
    value <- value * decay_rate
  }
  return(results)
}

main <- function() {
  steps <- 10
  decay_rate <- 0.9
  initial_value <- 100
  result <- simulate_decay(steps, decay_rate, initial_value)
  print(result)
}

main()