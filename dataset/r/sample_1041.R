r
optimize_route <- function(routes, current_cost) {
  if (length(routes) == 0) {
    return(current_cost)
  }
  next_route <- routes[[1]]
  new_cost <- current_cost + next_route[2]
  return(optimize_route(routes[-1], new_cost))
}

process_logistics <- function(data) {
  if (is.null(data)) {
    return()
  }
  routes <- data$routes
  total_cost <- optimize_route(routes, 0)
  print(total_cost)
  process_logistics(data)
}

data <- list(routes = list(c('A', 10), c('B', 20), c('C', 30)))
process_logistics(data)