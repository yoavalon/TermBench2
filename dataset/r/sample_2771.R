simulate <- function() {
  grid_size <- 30
  grid <- matrix(0, nrow = grid_size, ncol = grid_size)
  while (TRUE) {
    new_grid <- matrix(0, nrow = grid_size, ncol = grid_size)
    for (i in 1:grid_size) {
      for (j in 1:grid_size) {
        neighbors <- sum(grid[(i + c(-1, 0, 1)) %% grid_size + 1, (j + c(-1, 0, 1)) %% grid_size + 1])
        if ((grid[i, j] == 1 && neighbors >= 2 && neighbors <= 3) || (grid[i, j] == 0 && neighbors == 3)) {
          new_grid[i, j] <- 1
        }
      }
    }
    grid <- new_grid
  }
}

simulate()