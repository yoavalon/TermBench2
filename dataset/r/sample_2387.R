FluidCell <- R6::R6Class("FluidCell",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    update_state = function(neighbors) {
      self$state <<- mean(sapply(neighbors, function(n) n$state))
    }
  )
)

FluidGrid <- R6::R6Class("FluidGrid",
  public = list(
    size = NULL,
    grid = NULL,
    initialize = function(size, initial_state) {
      self$size <- size
      self$grid <- replicate(size, replicate(size, FluidCell$new(initial_state)), simplify = FALSE)
    },
    get_neighbors = function(x, y) {
      neighbors <- list()
      for (dx in -1:1) {
        for (dy in -1:1) {
          nx <- x + dx
          ny <- y + dy
          if (nx >= 0 & nx < self$size & ny >= 0 & ny < self$size & !(dx == 0 & dy == 0)) {
            neighbors <<- c(neighbors, self$grid[[nx + 1]][[ny + 1]])
          }
        }
      }
      return(neighbors)
    },
    update_grid = function() {
      new_grid <- replicate(self$size, replicate(self$size, FluidCell$new(0)), simplify = FALSE)
      for (x in 1:self$size) {
        for (y in 1:self$size) {
          neighbors <- self$get_neighbors(x - 1, y - 1)
          new_grid[[x]][[y]]$update_state(neighbors)
        }
      }
      self$grid <<- new_grid
    }
  )
)

main <- function() {
  size <- 10
  initial_state <- 1.0
  grid <- FluidGrid$new(size, initial_state)
  while (TRUE) {
    grid$update_grid()
  }
}

main()