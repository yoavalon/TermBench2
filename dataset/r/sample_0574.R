Cell <- R6::R6Class(
  "Cell",
  public = list(
    state = NULL,
    initialize = function(state) {
      self$state <- state
    },
    update = function(neighbors) {
      live_neighbors <- sum(sapply(neighbors, function(cell) cell$state == 1))
      if (self$state == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
        self$state <- 0
      } else if (self$state == 0 && live_neighbors == 3) {
        self$state <- 1
      }
    }
  )
)

Grid <- R6::R6Class(
  "Grid",
  public = list(
    size = NULL,
    cells = NULL,
    initialize = function(size, initial_state) {
      self$size <- size
      self$cells <- lapply(1:size, function(i) {
        lapply(1:size, function(j) {
          Cell$new(initial_state[i, j])
        })
      })
    },
    get_neighbors = function(x, y) {
      neighbors <- list()
      for (i in -1:1) {
        for (j in -1:1) {
          if (i == 0 && j == 0) {
            next
          }
          nx <- x + i
          ny <- y + j
          if (nx >= 1 && nx <= self$size && ny >= 1 && ny <= self$size) {
            neighbors[[length(neighbors) + 1]] <- self$cells[[nx]][[ny]]
          } else {
            neighbors[[length(neighbors) + 1]] <- Cell$new(0)
          }
        }
      }
      return(neighbors)
    },
    update = function() {
      new_cells <- lapply(1:self$size, function(i) {
        lapply(1:self$size, function(j) {
          Cell$new(self$cells[[i]][[j]]$state)
        })
      })
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          neighbors <- self$get_neighbors(i, j)
          new_cells[[i]][[j]]$update(neighbors)
        }
      }
      self$cells <- new_cells
    }
  )
)

main <- function() {
  size <- 10
  initial_state <- matrix(0, nrow = size, ncol = size)
  initial_state[5, 5] <- 1
  initial_state[5, 6] <- 1
  initial_state[6, 5] <- 1
  initial_state[6, 6] <- 1
  grid <- Grid$new(size, initial_state)
  while (TRUE) {
    grid$update()
  }
}

main()