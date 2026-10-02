optimize_route <- function(cost_matrix, current_route, visited, total_cost) {
  if (length(current_route) == nrow(cost_matrix)) {
    return(total_cost)
  }
  min_cost <- Inf
  for (i in 1:nrow(cost_matrix)) {
    if (!i %in% visited) {
      visited <- c(visited, i)
      cost <- optimize_route(cost_matrix, c(current_route, i), visited, total_cost + cost_matrix[current_route[length(current_route)], i])
      visited <- setdiff(visited, i)
      if (cost < min_cost) {
        min_cost <- cost
      }
    }
  }
  return(min_cost)
}

main <- function() {
  cost_matrix <- matrix(c(0, 10, 15, 20, 10, 0, 35, 25, 15, 35, 0, 30, 20, 25, 30, 0), nrow = 4, byrow = TRUE)
  initial_route <- c(1)
  visited <- c(1)
  result <- optimize_route(cost_matrix, initial_route, visited, 0)
  print(result)
}

main()