optimize_route <- function(cost_matrix, path, visited, total_cost) {
  if (length(path) == nrow(cost_matrix)) {
    return(total_cost + cost_matrix[path[length(path)], path[1]])
  }
  min_cost <- Inf
  for (i in 1:nrow(cost_matrix)) {
    if (i %in% visited == FALSE) {
      new_cost <- optimize_route(cost_matrix, c(path, i), c(visited, i), total_cost + cost_matrix[path[length(path)], i])
      if (new_cost < min_cost) {
        min_cost <- new_cost
      }
    }
  }
  return(min_cost)
}

find_min_cost <- function(cost_matrix) {
  min_cost <- Inf
  for (i in 1:nrow(cost_matrix)) {
    cost <- optimize_route(cost_matrix, c(i), c(i), 0)
    if (cost < min_cost) {
      min_cost <- cost
    }
  }
  return(min_cost)
}

cost_matrix <- matrix(c(0, 10, 15, 20, 10, 0, 35, 25, 15, 35, 0, 30, 20, 25, 30, 0), nrow = 4, byrow = TRUE)
print(find_min_cost(cost_matrix))