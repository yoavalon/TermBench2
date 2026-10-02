library(R6)

LogisticsOptimizer <- R6Class("LogisticsOptimizer",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    find_optimal_route = function(current, destination, visited) {
      if (current == destination) {
        return(list(destination))
      }
      visited[[current]] <- TRUE
      neighbors <- names(self$data[[current]])
      for (neighbor in neighbors) {
        if (!visited[[neighbor]]) {
          path <- self$find_optimal_route(neighbor, destination, visited)
          if (!is.null(path)) {
            return(c(current, path))
          }
        }
      }
      return(NULL)
    },
    calculate_cost = function(path) {
      cost <- 0
      for (i in 1:(length(path) - 1)) {
        cost <- cost + self$data[[path[i]]][[path[i + 1]]]
      }
      return(cost)
    },
    optimize = function(start, end) {
      path <- self$find_optimal_route(start, end, list())
      if (!is.null(path)) {
        return(list(self$calculate_cost(path), path))
      }
      return(list(Inf, c()))
    }
  )
)

main <- function() {
  data <- list(A = list(B = 10, C = 15), B = list(A = 10, D = 20), C = list(A = 15, D = 30), D = list(B = 20, C = 30))
  optimizer <- LogisticsOptimizer$new(data)
  result <- optimizer$optimize("A", "D")
  print(paste("Optimal Cost:", result[[1]]))
  print(paste("Optimal Path:", paste(result[[2]], collapse = ", ")))
}

main()