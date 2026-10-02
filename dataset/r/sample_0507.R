library(shiny)

Grid <- R6::R6Class("Grid",
  public = list(
    size = NULL,
    grid = NULL,
    
    initialize = function(size) {
      self$size <- size
      self$grid <- replicate(size, replicate(size, sample(0:1, 1)), simplify = FALSE)
    },
    
    update = function() {
      new_grid <- replicate(self$size, replicate(self$size, 0), simplify = FALSE)
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          state <- self$grid[[i]][[j]]
          neighbors <- self$count_neighbors(i, j)
          if (state == 0 & neighbors == 3) {
            new_grid[[i]][[j]] <- 1
          } else if (state == 1 & (neighbors < 2 | neighbors > 3)) {
            new_grid[[i]][[j]] <- 0
          } else {
            new_grid[[i]][[j]] <- state
          }
        }
      }
      self$grid <- new_grid
    },
    
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(x + 1, self$size)) {
        for (j in max(1, y - 1):min(y + 1, self$size)) {
          if (!(i == x & j == y)) {
            count <- count + self$grid[[i]][[j]]
          }
        }
      }
      return(count)
    }
  )
)

Simulation <- R6::R6Class("Simulation",
  public = list(
    grid = NULL,
    
    initialize = function(grid) {
      self$grid <- grid
    },
    
    run = function() {
      while (TRUE) {
        self$grid$update()
        self$display()
      }
    },
    
    display = function() {
      for (row in self$grid$grid) {
        cat(paste0(ifelse(row == 1, '#', ' '), collapse = ''))
        cat('\n')
      }
      cat(rep('-', self$grid$size), '\n')
    }
  )
)

main <- function() {
  size <- 50
  grid <- Grid$new(size)
  simulation <- Simulation$new(grid)
  simulation$run()
}

main()