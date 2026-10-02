r
Grid <- R6::R6Class("Grid",
  public = list(
    size = NULL,
    state = NULL,
    initialize = function(size) {
      self$size <- size
      self$state <- matrix(0, nrow = size, ncol = size)
    },
    update = function() {
      new_state <- matrix(0, nrow = self$size, ncol = self$size)
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          neighbors <- self$get_neighbors(i, j)
          if (self$state[i, j] == 0 & neighbors == 3) {
            new_state[i, j] <- 1
          } else if (self$state[i, j] == 1 & (neighbors < 2 | neighbors > 3)) {
            new_state[i, j] <- 0
          } else {
            new_state[i, j] <- self$state[i, j]
          }
        }
      }
      self$state <- new_state
    },
    get_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(x + 1, self$size)) {
        for (j in max(1, y - 1):min(y + 1, self$size)) {
          if (!(i == x & j == y) & self$state[i, j] == 1) {
            count <- count + 1
          }
        }
      }
      return(count)
    }
  )
)

display <- function(grid) {
  for (row in grid$state) {
    cat(paste(ifelse(row == 1, "*", " "), collapse = ""), "\n")
  }
  cat("\n")
}

main <- function() {
  size <- 10
  grid <- Grid$new(size)
  for (i in 1:size) {
    for (j in 1:size) {
      if (i %% 2 == 0 & j %% 2 == 0) {
        grid$state[i, j] <- 1
      }
    }
  }
  while (TRUE) {
    display(grid)
    grid$update()
  }
}

main()