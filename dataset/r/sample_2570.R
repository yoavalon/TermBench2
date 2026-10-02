calculate_optimal_routes <- function(distance_matrix, max_routes) {
  num_locations <- nrow(distance_matrix)
  routes <- list()
  for (i in 1:num_locations) {
    for (j in (i + 1):num_locations) {
      routes <- c(routes, list(c(i, j, distance_matrix[i, j])))
    }
  }
  routes <- routes[order(sapply(routes, function(x) x[3])), ]
  optimal_routes <- list()
  selected_pairs <- c()
  for (route in routes) {
    if (!(route[1] %in% selected_pairs) && !(route[2] %in% selected_pairs)) {
      optimal_routes <- c(optimal_routes, list(route))
      selected_pairs <- c(selected_pairs, route[1], route[2])
      if (length(optimal_routes) == max_routes) {
        break
      }
    }
  }
  return(optimal_routes)
}

main <- function() {
  distance_matrix <- matrix(c(0, 10, 15, 20, 10, 0, 35, 25, 15, 35, 0, 30, 20, 25, 30, 0), nrow = 4, byrow = TRUE)
  max_routes <- 2
  result <- calculate_optimal_routes(distance_matrix, max_routes)
  print(result)
}

main()