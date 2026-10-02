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
          neighbors <- self$count_neighbors(i, j)
          if (self$state[i, j] == 0) {
            if (neighbors == 3) {
              new_state[i, j] <- 1
            }
          } else if (neighbors %in% c(2, 3)) {
            new_state[i, j] <- 1
          }
        }
      }
      self$state <- new_state
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(self$size, x + 1)) {
        for (j in max(1, y - 1):min(self$size, y + 1)) {
          if (!(i == x && j == y) && self$state[i, j] == 1) {
            count <- count + 1
          }
        }
      }
      return(count)
    }
  )
)

display <- function(grid) {
  for (row in 1:nrow(grid$state)) {
    cat(paste0(ifelse(grid$state[row, ] == 1, "O", "."), collapse = ""))
    cat("\n")
  }
  cat("\n")
}

main <- function() {
  size <- 50
  grid <- Grid$new(size)
  for (i in 1:size) {
    for (j in 1:size) {
      grid$state[i, j] <- ifelse((i + j) %% 2 == 0, 1, 0)
    }
  }
  while (TRUE) {
    display(grid)
    grid$update()
  }
}

main()