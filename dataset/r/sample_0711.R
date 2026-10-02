r
optimize_route <- function(routes, current_route, visited, cost) {
  if (length(current_route) == length(routes)) {
    return(cost)
  }
  min_cost <- Inf
  for (i in 1:length(routes)) {
    if (!i %in% visited) {
      new_cost <- cost + routes[current_route[length(current_route)]][i]
      new_visited <- union(visited, i)
      new_route <- c(current_route, i)
      min_cost <- min(min_cost, optimize_route(routes, new_route, new_visited, new_cost))
    }
  }
  return(min_cost)
}

find_min_cost <- function(routes) {
  min_cost <- Inf
  for (i in 1:length(routes)) {
    min_cost <- min(min_cost, optimize_route(routes, i, i, 0))
  }
  return(min_cost)
}

main <- function() {
  routes <- matrix(c(0, 10, 15, 20, 10, 0, 35, 25, 15, 35, 0, 30, 20, 25, 30, 0), nrow = 4, byrow = TRUE)
  print(find_min_cost(routes))
}

main()