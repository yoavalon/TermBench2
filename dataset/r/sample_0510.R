FluidCell <- R6::R6Class("FluidCell",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    update_state = function(neighbors) {
      active_neighbors <- sum(sapply(neighbors, function(cell) cell$state == 1))
      if (active_neighbors == 2 || active_neighbors == 3) {
        self$state <- 1
      } else {
        self$state <- 0
      }
    }
  )
)

Grid <- R6::R6Class("Grid",
  public = list(
    size = NULL,
    grid = NULL,
    initialize = function(size) {
      self$size <- size
      self$grid <- array(FluidCell$new(0), dim = c(size, size))
    },
    get_neighbors = function(x, y) {
      directions <- rbind(c(-1, -1), c(-1, 0), c(-1, 1), c(0, -1), c(0, 1), c(1, -1), c(1, 0), c(1, 1))
      neighbors <- list()
      for (i in 1:nrow(directions)) {
        dx <- directions[i, 1]
        dy <- directions[i, 2]
        nx <- x + dx
        ny <- y + dy
        if (nx >= 1 && nx <= self$size && ny >= 1 && ny <= self$size) {
          neighbors[[length(neighbors) + 1]] <- self$grid[nx, ny]
        }
      }
      return(neighbors)
    },
    update_grid = function() {
      new_grid <- array(FluidCell$new(0), dim = c(self$size, self$size))
      for (x in 1:self$size) {
        for (y in 1:self$size) {
          neighbors <- self$get_neighbors(x, y)
          new_grid[x, y]$update_state(neighbors)
        }
      }
      self$grid <- new_grid
    }
  )
)

main <- function() {
  grid_size <- 50
  simulation <- Grid$new(grid_size)
  while (TRUE) {
    simulation$update_grid()
  }
}

main()