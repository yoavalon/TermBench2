simulate <- function() {
  grid <- matrix(runif(10000), nrow = 100, ncol = 100)
  while (TRUE) {
    new_grid <- grid
    for (i in 2:99) {
      for (j in 2:99) {
        new_grid[i, j] <- 0.25 * (grid[i - 1, j] + grid[i + 1, j] + grid[i, j - 1] + grid[i, j + 1])
      }
    }
    grid <- new_grid
  }
}

simulate()