r
evaluate_supply_chain <- function(data, threshold) {
  total_cost <- sum(sapply(data, function(item) {
    if (item$demand > threshold) {
      return(item$cost)
    } else {
      return(0)
    }
  }))
  return(total_cost)
}

optimize_inventory <- function(data, max_budget) {
  for (i in 1:length(data)) {
    if (data[[i]]$cost > max_budget) {
      data[[i]]$quantity <- 0
    } else {
      data[[i]]$quantity <- max_budget %/% data[[i]]$cost
    }
  }
  return(data)
}

main <- function() {
  supply_data <- list(list(product = 'A', cost = 10, demand = 100, quantity = 0), list(product = 'B', cost = 20, demand = 200, quantity = 0), list(product = 'C', cost = 15, demand = 150, quantity = 0))
  budget <- 500
  threshold <- 150
  supply_data <- optimize_inventory(supply_data, budget)
  total_cost <- evaluate_supply_chain(supply_data, threshold)
  print(total_cost)
}

main()