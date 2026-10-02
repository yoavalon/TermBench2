# Define the FluidCell class
FluidCell <- R6::R6Class("FluidCell",
  public = list(
    state = NULL,
    initialize = function(state = 0) {
      self$state <- state
    },
    update = function(neighbors) {
      new_state <- sum(sapply(neighbors, function(n) n$state)) %/% length(neighbors)
      self$state <- new_state
    }
  )
)

# Define the Grid class
Grid <- R6::R6Class("Grid",
  public = list(
    width = NULL,
    height = NULL,
    grid = NULL,
    initialize = function(width, height, initial_state = 0) {
      self$width <- width
      self$height <- height
      self$grid <- lapply(1:height, function(y) lapply(1:width, function(x) FluidCell$new(initial_state)))
    },
    get_neighbors = function(x, y) {
      directions <- list(c(-1, 0), c(1, 0), c(0, -1), c(0, 1))
      neighbors <- list()
      for (dir in directions) {
        nx <- x + dir[1]
        ny <- y + dir[2]
        if (nx >= 1 && nx <= self$width && ny >= 1 && ny <= self$height) {
          neighbors[[length(neighbors) + 1]] <- self$grid[[ny]][[nx]]
        }
      }
      return(neighbors)
    },
    update_cells = function() {
      for (y in 1:self$height) {
        for (x in 1:self$width) {
          neighbors <- self$get_neighbors(x, y)
          self$grid[[y]][[x]]$update(neighbors)
        }
      }
    }
  )
)

# Define the Simulation class
Simulation <- R6::R6Class("Simulation",
  public = list(
    grid = NULL,
    initialize = function(grid) {
      self$grid <- grid
    },
    run = function() {
      while (TRUE) {
        self$grid$update_cells()
      }
    }
  )
)

# Main function
main <- function() {
  grid <- Grid$new(10, 10, initial_state = 50)
  simulation <- Simulation$new(grid)
  simulation$run()
}

# Call the main function
main()