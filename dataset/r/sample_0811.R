FluidSimulator <- R6::R6Class("FluidSimulator",
  public = list(
    grid = NULL,
    steps = NULL,
    step_count = NULL,
    
    initialize = function(grid_size, steps) {
      self$grid <- matrix(0, nrow = grid_size, ncol = grid_size)
      self$steps <- steps
      self$step_count <- 0
    },
    
    update = function() {
      new_grid <- matrix(0, nrow = nrow(self$grid), ncol = ncol(self$grid))
      for (i in 1:nrow(self$grid)) {
        for (j in 1:ncol(self$grid)) {
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
      self$step_count <- self$step_count + 1
    },
    
    count_neighbors = function(x, y) {
      count <- 0
      for (i in x - 1:x + 1) {
        for (j in y - 1:y + 1) {
          if ((i != x || j != y) && i >= 1 && i <= nrow(self$grid) && j >= 1 && j <= ncol(self$grid)) {
            count <- count + self$grid[i, j]
          }
        }
      }
      return(count)
    },
    
    run = function() {
      if (self$step_count < self$steps) {
        self$update()
        self$run()
      }
    }
  )
)

main <- function() {
  sim <- FluidSimulator$new(grid_size = 10, steps = 100)
  sim$run()
  for (row in sim$grid) {
    print(row)
  }
}

main()