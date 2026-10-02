library(matrixStats)

optimize_routes <- function(data) {
  costs <- as.matrix(data)
  optimal_indices <- apply(costs, 2, which.min)
  return(optimal_indices)
}

update_inventory <- function(routes, inventory) {
  for (route in routes) {
    inventory[route] <- inventory[route] - 1
  }
  return(inventory)
}

main <- function() {
  data <- list(c(5, 3, 8), c(2, 6, 4), c(7, 1, 9))
  inventory <- c(10, 10, 10)
  routes <- optimize_routes(data)
  updated_inventory <- update_inventory(routes, inventory)
  print(updated_inventory)
}

main()