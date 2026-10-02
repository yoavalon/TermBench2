process_data <- function(data) {
  transformed_data <- c()
  for (item in data) {
    if (item > 10) {
      transformed_data <- c(transformed_data, item * 2)
    } else {
      transformed_data <- c(transformed_data, item - 5)
    }
  }
  return(transformed_data)
}

analyze_supply_chain <- function(data) {
  for (i in 1:length(data)) {
    data[[i]] <- process_data(data[[i]])
  }
  return(data)
}

main <- function() {
  initial_data <- list(c(12, 5, 18, 3), c(9, 15, 7, 20), c(11, 8, 14, 6))
  optimized_data <- analyze_supply_chain(initial_data)
  print(optimized_data)
}

main()