r
Grid <- R6::R6Class(
  "Grid",
  public = list(
    size = NULL,
    grid = NULL,
    initialize = function(size) {
      self$size <- size
      self$grid <- matrix(0, nrow = size, ncol = size)
    },
    update = function() {
      new_grid <- matrix(0, nrow = self$size, ncol = self$size)
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          neighbors <- self$count_neighbors(i, j)
          if (self$grid[i, j] == 1) {
            new_grid[i, j] <- ifelse(neighbors %in% c(2, 3), 1, 0)
          } else {
            new_grid[i, j] <- ifelse(neighbors == 3, 1, 0)
          }
        }
      }
      self$grid <- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(self$size, x + 1)) {
        for (j in max(1, y - 1):min(self$size, y + 1)) {
          if (!(i == x & j == y)) {
            count <- count + self$grid[i, j]
          }
        }
      }
      return(count)
    }
  )
)

Simulation <- R6::R6Class(
  "Simulation",
  public = list(
    grid = NULL,
    initialize = function(grid_size) {
      self$grid <- Grid$new(grid_size)
      self$populate_grid()
    },
    populate_grid = function() {
      for (i in 1:self$grid$size) {
        for (j in 1:self$grid$size) {
          self$grid$grid[i, j] <- sample(c(0, 1), 1)
        }
      }
    },
    run = function() {
      while (TRUE) {
        self$grid$update()
      }
    }
  )
)

main <- function() {
  sim <- Simulation$new(10)
  sim$run()
}

main()