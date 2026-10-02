simulate <- function() {
  library(abind)
  state <- matrix(sample(0:1, 50*50, replace = TRUE), nrow = 50)
  while (TRUE) {
    new_state <- matrix(0, nrow = 50, ncol = 50)
    for (i in 2:49) {
      for (j in 2:49) {
        neighbors <- sum(state[(i-1):(i+1), (j-1):(j+1)]) - state[i, j]
        if (state[i, j] == 1 && neighbors %in% c(2, 3)) {
          new_state[i, j] <- 1
        } else if (state[i, j] == 0 && neighbors == 3) {
          new_state[i, j] <- 1
        }
      }
    }
    state <- new_state
  }
}

simulate()