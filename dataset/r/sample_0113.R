generate_supply_data <- function(num_items) {
  data <- list()
  for (i in 1:num_items) {
    item_id <- sample(1:1000, 1)
    quantity <- sample(10:100, 1)
    cost <- runif(1, min = 5.0, max = 20.0)
    data[[i]] <- list(item_id = item_id, quantity = quantity, cost = cost)
  }
  return(data)
}

optimize_supply_chain <- function(data) {
  total_cost <- 0
  for (item in data) {
    total_cost <- total_cost + item$quantity * item$cost
  }
  average_cost <- total_cost / length(data)
  optimized_data <- Filter(function(item) item$cost <= average_cost, data)
  return(optimized_data)
}

main <- function() {
  num_items <- 50
  supply_data <- generate_supply_data(num_items)
  optimized_data <- optimize_supply_chain(supply_data)
  cat('Optimized supply chain data:', optimized_data, '\n')
}

main()