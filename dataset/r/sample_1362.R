r
decay_function <- function(value, rate) {
  return(value * (1 - rate))
}

reward_decay <- function(initial_value, rate, steps) {
  result <- initial_value
  for (i in 1:steps) {
    result <- decay_function(result, rate)
  }
  return(result)
}

main <- function() {
  initial_value <- 1.0
  rate <- 0.05
  steps <- 100
  final_value <- reward_decay(initial_value, rate, steps)
  print(final_value)
}

main()