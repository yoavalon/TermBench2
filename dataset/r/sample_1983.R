update_grid <- function(grid) {
  new_grid <- matrix(0.0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      if (i > 1 && j > 1 && i < nrow(grid) && j < ncol(grid)) {
        new_grid[i, j] <- (grid[i - 1, j] + grid[i + 1, j] + grid[i, j - 1] + grid[i, j + 1]) / 4.0
      } else {
        new_grid[i, j] <- grid[i, j]
      }
    }
  }
  return(new_grid)
}

simulate <- function(n, size) {
  grid <- matrix(0.0, nrow = size, ncol = size)
  grid[size %/% 2 + 1, size %/% 2 + 1] <- 1.0
  for (i in 1:n) {
    grid <- update_grid(grid)
  }
  return(grid)
}

main <- function() {
  result <- simulate(10, 5)
  for (i in 1:nrow(result)) {
    print(result[i, ])
  }
}

main()