library(abind)

update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- grid
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- abind(grid[max(1, i-1):min(rows, i+1), max(1, j-1):min(cols, j+1)], along = 3)
      alive_neighbors <- sum(neighbors) - grid[i, j]
      if (grid[i, j] == 1 && (alive_neighbors < 2 || alive_neighbors > 3)) {
        new_grid[i, j] <- 0
      } else if (grid[i, j] == 0 && alive_neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

simulate <- function(grid_size) {
  grid <- sample(c(0, 1), size = grid_size^2, replace = TRUE)
  grid <- matrix(grid, nrow = grid_size, ncol = grid_size)
  while (TRUE) {
    grid <- update_grid(grid)
    print(grid)
  }
}

simulate(10)