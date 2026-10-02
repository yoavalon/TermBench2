fluid_dynamics <- function(grid) {
  size <- nrow(grid)
  next_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[max(1, i - 1):min(size, i + 1), max(1, j - 1):min(size, j + 1)])
      next_grid[i, j] <- ifelse(neighbors > 4, 1, 0)
    }
  }
  return(fluid_dynamics(next_grid))
}

grid <- matrix(0, nrow = 10, ncol = 10)
grid[5, 5] <- 1
fluid_dynamics(grid)