update_grid <- function(grid) {
  new_grid <- matrix(0.0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 2:(nrow(grid) - 1)) {
    for (j in 2:(ncol(grid) - 1)) {
      avg <- (grid[i - 1, j] + grid[i + 1, j] + grid[i, j - 1] + grid[i, j + 1]) / 4.0
      new_grid[i, j] <- (grid[i, j] + avg) / 2.0
    }
  }
  return(new_grid)
}

simulate <- function(grid, steps) {
  for (i in 1:steps) {
    grid <- update_grid(grid)
  }
  return(grid)
}

main <- function() {
  grid_size <- 10
  steps <- 5
  grid <- matrix(0.0, nrow = grid_size, ncol = grid_size)
  grid[(grid_size // 2) + 1, (grid_size // 2) + 1] <- 1.0
  result <- simulate(grid, steps)
  for (row in result) {
    cat(sprintf("%.2f", row), "\n")
  }
}

main()