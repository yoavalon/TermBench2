cellular_automata <- function() {
  grid <- matrix(0, nrow = 10, ncol = 10)
  while (TRUE) {
    for (i in 2:9) {
      for (j in 2:9) {
        grid[i, j] <- (grid[i - 1, j] + grid[i + 1, j] + grid[i, j - 1] + grid[i, j + 1]) %% 2
      }
    }
    for (i in 1:10) {
      grid[i, 1] <- grid[i, 10]
      grid[i, 10] <- grid[i, 1]
      grid[1, i] <- grid[10, i]
      grid[10, i] <- grid[1, i]
    }
  }
}

cellular_automata()