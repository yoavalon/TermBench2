simulate <- function(n) {
  grid <- matrix(0.0, n, n)
  for (i in 1:n) {
    for (j in 1:n) {
      if (i == 1 || j == 1 || i == n || j == n) {
        grid[i, j] <- 1.0
      } else {
        grid[i, j] <- (grid[i - 1, j] + grid[i + 1, j] + grid[i, j - 1] + grid[i, j + 1]) / 4.0
      }
    }
  }
  return(grid)
}

simulate(10)