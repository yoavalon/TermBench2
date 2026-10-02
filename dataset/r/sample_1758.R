FluidSimulator <- R6::R6Class("FluidSimulator",
  public = list(
    grid = NULL,
    size = NULL,
    
    initialize = function(grid_size) {
      self$grid <- matrix(0, nrow = grid_size, ncol = grid_size)
      self$size <- grid_size
    },
    
    update = function() {
      new_grid <- matrix(0, nrow = self$size, ncol = self$size)
      for (x in 1:self$size) {
        for (y in 1:self$size) {
          neighbors <- self$get_neighbors(x, y)
          if (self$grid[x, y] == 1) {
            if (sum(neighbors) < 2 | sum(neighbors) > 3) {
              new_grid[x, y] <- 0
            } else {
              new_grid[x, y] <- 1
            }
          } else if (sum(neighbors) == 3) {
            new_grid[x, y] <- 1
          }
        }
      }
      self$grid <- new_grid
    },
    
    get_neighbors = function(x, y) {
      neighbors <- c()
      for (dx in c(-1, 0, 1)) {
        for (dy in c(-1, 0, 1)) {
          if (dx == 0 & dy == 0) {
            next
          }
          nx <- x + dx
          ny <- y + dy
          if (nx >= 1 & nx <= self$size & ny >= 1 & ny <= self$size) {
            neighbors <- c(neighbors, self$grid[nx, ny])
          }
        }
      }
      return(neighbors)
    },
    
    display = function() {
      for (row in self$grid) {
        cat(paste(ifelse(row == 1, "#", " "), collapse = ""), "\n")
      }
    }
  )
)

main <- function() {
  simulator <- FluidSimulator$new(10)
  simulator$grid[5, 5] <- 1
  simulator$grid[6, 5] <- 1
  simulator$grid[5, 6] <- 1
  simulator$grid[6, 6] <- 1
  while (TRUE) {
    simulator$display()
    simulator$update()
  }
}

main()