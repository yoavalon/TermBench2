Grid <- setRefClass("Grid",
  fields = list(size = "numeric", state = "matrix"),
  methods = list(
    initialize = function(size, initial_state) {
      .self$size <- size
      .self$state <- initial_state
    },
    update = function() {
      new_state <- matrix(0, nrow = .self$size, ncol = .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          neighbors <- .self$count_neighbors(i, j)
          if (.self$state[i, j] == 1 && (neighbors == 2 || neighbors == 3)) {
            new_state[i, j] <- 1
          } else if (.self$state[i, j] == 0 && neighbors == 3) {
            new_state[i, j] <- 1
          }
        }
      }
      .self$state <- new_state
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(.self$size, x + 1)) {
        for (j in max(1, y - 1):min(.self$size, y + 1)) {
          if (!(i == x && j == y) && .self$state[i, j] == 1) {
            count <- count + 1
          }
        }
      }
      return(count)
    }
  )
)

generate_initial_state <- function(size, density) {
  initial_state <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      if (runif(1) < density) {
        initial_state[i, j] <- 1
      }
    }
  }
  return(initial_state)
}

main <- function() {
  size <- 100
  density <- 0.2
  grid <- Grid(size, generate_initial_state(size, density))
  while (TRUE) {
    grid$update()
  }
}

main()