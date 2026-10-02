optimize_supply_chain <- function(data) {
  processed_data <- list()
  for (item in data) {
    if (item$quantity > 0) {
      processed_data <- c(processed_data, list(item))
    }
  }
  return(processed_data)
}

analyze_boundaries <- function(data) {
  min_quantity <- Inf
  max_quantity <- -Inf
  for (item in data) {
    if (item$quantity < min_quantity) {
      min_quantity <- item$quantity
    }
    if (item$quantity > max_quantity) {
      max_quantity <- item$quantity
    }
  }
  return(c(min_quantity, max_quantity))
}

main <- function() {
  supply_data <- list(list(product = 'A', quantity = 10), list(product = 'B', quantity = 0), list(product = 'C', quantity = 25))
  optimized_data <- optimize_supply_chain(supply_data)
  min_q <- analyze_boundaries(optimized_data)[1]
  max_q <- analyze_boundaries(optimized_data)[2]
  cat('Minimum Quantity:', min_q, ', Maximum Quantity:', max_q, '\n')
}

main()