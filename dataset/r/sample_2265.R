update_grid <- function(grid, size) {
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 2:(size - 1)) {
    for (j in 2:(size - 1)) {
      neighbors <- grid[(i-1):(i+1), (j-1):(j+1)]
      neighbors_sum <- sum(neighbors) - grid[i, j]
      if (grid[i, j] == 0 & neighbors_sum > 2) {
        new_grid[i, j] <- 1
      } else if (grid[i, j] == 1 & (neighbors_sum < 2 | neighbors_sum > 3)) {
        new_grid[i, j] <- 0
      } else {
        new_grid[i, j] <- grid[i, j]
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 50
  grid <- matrix(0, nrow = size, ncol = size)
  grid[size %/% 2, size %/% 2] <- 1
  while (TRUE) {
    grid <- update_grid(grid, size)
  }
}

main()