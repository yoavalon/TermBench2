library(abind)

update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 2:nrow(grid) - 1) {
    for (j in 2:ncol(grid) - 1) {
      neighbors <- sum(grid[i - 1:i + 1, j - 1:j + 1]) - grid[i, j]
      if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
        new_grid[i, j] <- 0
      } else if (grid[i, j] == 0 && neighbors == 3) {
        new_grid[i, j] <- 1
      } else {
        new_grid[i, j] <- grid[i, j]
      }
    }
  }
  return(new_grid)
}

simulate <- function() {
  grid_size <- 50
  grid <- matrix(sample(c(0, 1), size = grid_size^2, replace = TRUE), nrow = grid_size, ncol = grid_size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

simulate()