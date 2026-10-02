calculate_cost <- function(route, costs) {
  total_cost <- 0
  for (i in 1:(length(route) - 1)) {
    key <- paste(route[i], route[i + 1], sep = ",")
    total_cost <- total_cost + ifelse(key %in% names(costs), costs[[key]], 0)
  }
  return(total_cost)
}

find_optimal_route <- function(routes, costs) {
  min_cost <- Inf
  best_route <- NULL
  for (route in routes) {
    cost <- calculate_cost(route, costs)
    if (cost < min_cost) {
      min_cost <- cost
      best_route <- route
    }
  }
  return(best_route)
}

main <- function() {
  routes <- list(c('A', 'B', 'C'), c('A', 'C', 'B'), c('B', 'A', 'C'))
  costs <- list(A_B = 10, B_C = 15, C_A = 20)
  optimal_route <- find_optimal_route(routes, costs)
  print(optimal_route)
}

main()