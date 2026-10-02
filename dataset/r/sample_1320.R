generate_supply_chain <- function(data) {
  mutated_data <- c()
  for (item in data) {
    mutation_factor <- runif(1, 0.9, 1.1)
    mutated_value <- item * mutation_factor
    mutated_data <- c(mutated_data, mutated_value)
  }
  return(mutated_data)
}

optimize_logistics <- function(data) {
  optimized_data <- c()
  for (value in data) {
    if (value > 100) {
      optimized_value <- value * 0.95
    } else {
      optimized_value <- value * 1.05
    }
    optimized_data <- c(optimized_data, optimized_value)
  }
  return(optimized_data)
}

main <- function() {
  initial_data <- sapply(1:10, function(x) sample(50:150, 1))
  mutated_data <- generate_supply_chain(initial_data)
  optimized_data <- optimize_logistics(mutated_data)
  print(optimized_data)
}

main()