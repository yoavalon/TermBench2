simulate <- function() {
  grid <- matrix(0, nrow = 50, ncol = 50)
  while (TRUE) {
    new_grid <- matrix(0, nrow = 50, ncol = 50)
    for (i in 2:49) {
      for (j in 2:49) {
        neighbors <- grid[i - 1, j] + grid[i + 1, j] + grid[i, j - 1] + grid[i, j + 1]
        new_grid[i, j] <- ifelse(neighbors == 2, 1, 0)
      }
    }
    grid <- new_grid
  }
}

simulate()