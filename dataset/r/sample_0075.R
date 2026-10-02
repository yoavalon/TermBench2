optimize_supply_chain <- function(data) {
  calculate_cost <- function(route) {
    sum(data$distances[[route[i]]][[route[i + 1]]] for i in 1:(length(route) - 1))
  }
  
  find_best_route <- function(routes) {
    min(routes, key = calculate_cost)
  }
  
  routes <- data$routes
  best_route <- find_best_route(routes)
  return(best_route)
}

data <- list(distances = list(A = list(B = 10, C = 15), B = list(A = 10, C = 35), C = list(A = 15, B = 35)), routes = list(c('A', 'B', 'C'), c('A', 'C', 'B')))
optimize_supply_chain(data)