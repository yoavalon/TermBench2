optimize_route <- function(routes, visited, current, destination, cost) {
  if (current == destination) {
    return(cost)
  }
  min_cost <- Inf
  for (route in routes[[current]]) {
    if (!(route[1] %in% visited)) {
      visited <- c(visited, route[1])
      new_cost <- optimize_route(routes, visited, route[1], destination, cost + route[2])
      visited <- setdiff(visited, route[1])
      if (new_cost < min_cost) {
        min_cost <- new_cost
      }
    }
  }
  return(min_cost)
}

find_optimal_path <- function(routes, start, end) {
  visited <- c(start)
  return(optimize_route(routes, visited, start, end, 0))
}

routes <- list(A = list(c('B', 10), c('C', 15)), B = list(c('C', 35), c('D', 25)), C = list(c('D', 30)), D = list())
start <- 'A'
end <- 'D'
print(find_optimal_path(routes, start, end))