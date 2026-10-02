Automaton <- R6::R6Class("Automaton",
  public = list(
    grid = NULL,
    size = NULL,
    
    initialize = function(grid_size) {
      self$grid <- matrix(0, nrow = grid_size, ncol = grid_size)
      self$size <- grid_size
    },
    
    update = function() {
      new_grid <- matrix(0, nrow = self$size, ncol = self$size)
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          neighbors <- self$count_neighbors(i, j)
          if (self$grid[i, j] == 0 && neighbors == 3) {
            new_grid[i, j] <- 1
          } else if (self$grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
            new_grid[i, j] <- 0
          } else {
            new_grid[i, j] <- self$grid[i, j]
          }
        }
      }
      self$grid <- new_grid
    },
    
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(self$size, x + 1)) {
        for (j in max(1, y - 1):min(self$size, y + 1)) {
          if (!(i == x && j == y) && self$grid[i, j] == 1) {
            count <- count + 1
          }
        }
      }
      return(count)
    }
  )
)

simulate <- function(automaton, steps) {
  for (i in 1:steps) {
    automaton$update()
  }
}

main <- function() {
  grid_size <- 10
  steps <- 50
  automaton <- Automaton$new(grid_size)
  simulate(automaton, steps)
}

main()