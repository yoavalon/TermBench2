simulate_flow <- function(n) {
  grid <- matrix(0.0, n, n)
  while (TRUE) {
    new_grid <- matrix(0.0, n, n)
    for (i in 1:n) {
      for (j in 1:n) {
        new_grid[i, j] <- (grid[i, (j - 1) %% n + 1] + grid[i, (j + 1) %% n + 1] + grid[(i - 1) %% n + 1, j] + grid[(i + 1) %% n + 1, j]) / 4
      }
    }
    grid <- new_grid
  }
}

simulate_flow(10)