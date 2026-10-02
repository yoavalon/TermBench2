Grid <- R6::R6Class("Grid",
  public = list(
    initialize = function(size) {
      self$grid <- matrix(0, nrow = size, ncol = size)
      self$size <- size
    },
    update = function() {
      new_grid <- matrix(0, nrow = self$size, ncol = self$size)
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          neighbors <- self$count_neighbors(i, j)
          if (self$grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
            new_grid[i, j] <- 0
          } else if (self$grid[i, j] == 0 && neighbors == 3) {
            new_grid[i, j] <- 1
          } else {
            new_grid[i, j] <- self$grid[i, j]
          }
        }
      }
      self$grid <- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in x - 1:x + 1) {
        for (j in y - 1:y + 1) {
          if ((i != x || j != y) && i > 0 && i <= self$size && j > 0 && j <= self$size) {
            count <- count + self$grid[i, j]
          }
        }
      }
      return(count)
    }
  )
)

Simulation <- R6::R6Class("Simulation",
  public = list(
    initialize = function(grid) {
      self$grid <- grid
      self$steps <- 0
    },
    run = function(max_steps) {
      while (self$steps < max_steps) {
        self$grid$update()
        self$steps <- self$steps + 1
      }
    }
  )
)

main <- function() {
  size <- 50
  max_steps <- 100
  grid <- Grid$new(size)
  simulation <- Simulation$new(grid)
  simulation$run(max_steps)
}

main()