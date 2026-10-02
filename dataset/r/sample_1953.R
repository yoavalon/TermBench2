decay_function <- function(current_value, decay_rate) {
  return(current_value * (1 - decay_rate))
}

termination_analysis <- function(initial_value, threshold, decay_rate) {
  value <- initial_value
  count <- 0
  while (value > threshold) {
    value <- decay_function(value, decay_rate)
    count <- count + 1
  }
  return(count)
}

main <- function() {
  initial_value <- 1.0
  threshold <- 0.01
  decay_rate <- 0.1
  result <- termination_analysis(initial_value, threshold, decay_rate)
  print(result)
}

main()