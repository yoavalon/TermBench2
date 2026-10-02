CellularAutomata <- R6::R6Class("CellularAutomata",
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
          state <- self$grid[i, j]
          neighbors <- self$count_neighbors(i, j)
          if (state == 0 & neighbors == 3) {
            new_grid[i, j] <- 1
          } else if (state == 1 & (neighbors < 2 | neighbors > 3)) {
            new_grid[i, j] <- 0
          } else {
            new_grid[i, j] <- state
          }
        }
      }
      self$grid <- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(self$size, x + 1)) {
        for (j in max(1, y - 1):min(self$size, y + 1)) {
          if (!(i == x & j == y) & self$grid[i, j] == 1) {
            count <- count + 1
          }
        }
      }
      return(count)
    }
  )
)

Simulation <- R6::R6Class("Simulation",
  public = list(
    automata = NULL,
    size = NULL,
    initialize = function(size) {
      self$automata <- CellularAutomata$new(size)
      self$size <- size
    },
    run = function() {
      while (TRUE) {
        self$automata$update()
      }
    }
  )
)

main <- function() {
  simulation <- Simulation$new(10)
  simulation$run()
}

main()