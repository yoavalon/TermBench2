decay_reward <- function(reward, decay_rate, steps) {
  for (i in 1:steps) {
    reward <- reward * decay_rate
  }
  return(reward)
}

process_data <- function(data, rate, iterations) {
  results <- list()
  for (item in data) {
    results <- c(results, decay_reward(item, rate, iterations))
  }
  return(results)
}

main <- function() {
  data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
  rate <- 0.95
  iterations <- 10
  output <- process_data(data, rate, iterations)
  print(output)
}

main()