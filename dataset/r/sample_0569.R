Grid <- setRefClass("Grid",
  fields = list(size = "numeric", state = "matrix"),
  methods = list(
    initialize = function(size) {
      .self$size <- size
      .self$state <- matrix(0, nrow = size, ncol = size)
    },
    update = function() {
      new_state <- matrix(0, nrow = .self$size, ncol = .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          neighbors <- .self$get_neighbors(i, j)
          alive_neighbors <- sum(neighbors)
          if (.self$state[i, j] == 1) {
            new_state[i, j] <- ifelse(2 <= alive_neighbors & alive_neighbors <= 3, 1, 0)
          } else {
            new_state[i, j] <- ifelse(alive_neighbors == 3, 1, 0)
          }
        }
      }
      .self$state <<- new_state
    },
    get_neighbors = function(x, y) {
      neighbors <- c()
      for (i in max(1, x - 1):min(.self$size, x + 1)) {
        for (j in max(1, y - 1):min(.self$size, y + 1)) {
          if (!(i == x & j == y)) {
            neighbors <- c(neighbors, .self$state[i, j])
          }
        }
      }
      return(neighbors)
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(grid = "Grid", iteration = "numeric"),
  methods = list(
    initialize = function(grid_size) {
      .self$grid <- new("Grid", size = grid_size)
      .self$iteration <- 0
    },
    run = function() {
      while (TRUE) {
        .self$grid$update()
        .self$iteration <<- .self$iteration + 1
      }
    }
  )
)

main <- function() {
  sim <- new("Simulation", grid_size = 10)
  sim$run()
}

main()