r
optimize_supply_chain <- function(data) {
  cost <- 0
  for (item in data) {
    cost <- cost + item$demand * item$price
  }
  return(cost)
}

adjust_inventory <- function(data, budget) {
  for (i in seq_along(data)) {
    item <- data[[i]]
    if (item$cost > budget) {
      item$demand <- 0
    } else {
      item$demand <- sample(1:10, 1)
    }
    data[[i]] <- item
  }
  return(data)
}

main <- function() {
  supply_data <- list(
    list(name = 'A', demand = 5, price = 20, cost = 50),
    list(name = 'B', demand = 3, price = 30, cost = 40),
    list(name = 'C', demand = 8, price = 10, cost = 30)
  )
  budget <- 100
  adjusted_data <- adjust_inventory(supply_data, budget)
  total_cost <- optimize_supply_chain(adjusted_data)
  print(total_cost)
}

main()