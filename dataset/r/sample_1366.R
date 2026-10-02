generate_data <- function(size) {
  data <- runif(size, min = -10, max = 10)
  return(data)
}

mutate_data <- function(data, mutation_rate) {
  mutated_data <- c()
  for (value in data) {
    if (runif(1) < mutation_rate) {
      mutated_data <- c(mutated_data, value * runif(1, min = 0.5, max = 1.5))
    } else {
      mutated_data <- c(mutated_data, value)
    }
  }
  return(mutated_data)
}

analyze_data <- function(data) {
  average <- mean(data)
  variance <- var(data)
  return(list(average = average, variance = variance))
}

main <- function() {
  initial_size <- 100
  mutation_rate <- 0.1
  data <- generate_data(initial_size)
  mutated_data <- mutate_data(data, mutation_rate)
  result <- analyze_data(mutated_data)
  cat('Average:', result$average, 'Variance:', result$variance, '\n')
}

main()