Grid <- R6::R6Class("Grid", 
  public = list(
    size = NULL,
    data = NULL,
    
    initialize = function(size) {
      self$size <- size
      self$data <- matrix(0, nrow = size, ncol = size)
    },
    
    update = function() {
      new_data <- matrix(0, nrow = self$size, ncol = self$size)
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          new_data[i, j] <- self$_calculate_next_state(i, j)
        }
      }
      self$data <- new_data
    },
    
    _calculate_next_state = function(i, j) {
      neighbors <- self$_get_neighbors(i, j)
      alive_count <- sum(neighbors)
      if (self$data[i, j] == 1) {
        return(ifelse(alive_count %in% c(2, 3), 1, 0))
      } else {
        return(ifelse(alive_count == 3, 1, 0))
      }
    },
    
    _get_neighbors = function(i, j) {
      neighbors <- c()
      for (x in max(1, i - 1):min(self$size, i + 1)) {
        for (y in max(1, j - 1):min(self$size, j + 1)) {
          if (!(x == i && y == j)) {
            neighbors <- c(neighbors, self$data[x, y])
          }
        }
      }
      return(neighbors)
    }
  )
)

main <- function() {
  grid_size <- 10
  grid <- Grid$new(grid_size)
  steps <- 50
  for (i in 1:steps) {
    grid$update()
  }
}

main()