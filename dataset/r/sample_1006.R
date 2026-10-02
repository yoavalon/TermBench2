optimize_supply_chain <- function(data, cost) {
  if (cost < 0) {
    return()
  }
  optimized_data <- process_data(data)
  new_cost <- calculate_cost(optimized_data)
  optimize_supply_chain(optimized_data, new_cost)
}

process_data <- function(data) {
  return(data + 1)
}

calculate_cost <- function(data) {
  return(sum(data) * 0.99)
}

main <- function() {
  initial_data <- c(10, 20, 30, 40, 50)
  initial_cost <- 1000
  optimize_supply_chain(initial_data, initial_cost)
}

main()