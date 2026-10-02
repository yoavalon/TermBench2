r
CellAutomata <- R6::R6Class(
  "CellAutomata",
  public = list(
    grid_size = NULL,
    grid = NULL,
    
    initialize = function(grid_size) {
      self$grid_size <- grid_size
      self$grid <- self$initialize_grid()
    },
    
    initialize_grid = function() {
      grid <- matrix(sample(0:1, size = self$grid_size^2, replace = TRUE), nrow = self$grid_size)
      return(grid)
    },
    
    update_grid = function() {
      new_grid <- matrix(0, nrow = self$grid_size, ncol = self$grid_size)
      for (i in 1:self$grid_size) {
        for (j in 1:self$grid_size) {
          neighbors <- self$count_neighbors(i, j)
          if (self$grid[i, j] == 1) {
            if (neighbors %in% c(2, 3)) {
              new_grid[i, j] <- 1
            }
          } else if (neighbors == 3) {
            new_grid[i, j] <- 1
          }
        }
      }
      self$grid <- new_grid
    },
    
    count_neighbors = function(x, y) {
      count <- 0
      for (i in -1:1) {
        for (j in -1:1) {
          if (i == 0 & j == 0) {
            next
          }
          ni <- ((x + i - 1) %% self$grid_size) + 1
          nj <- ((y + j - 1) %% self$grid_size) + 1
          count <- count + self$grid[ni, nj]
        }
      }
      return(count)
    }
  )
)

main <- function() {
  size <- 50
  automata <- CellAutomata$new(size)
  while (TRUE) {
    automata$update_grid()
  }
}

main()