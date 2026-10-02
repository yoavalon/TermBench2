cellular_automata <- function(width, height) {
  grid <- matrix(0, nrow = height, ncol = width)
  while (TRUE) {
    new_grid <- grid
    for (i in 2:(height - 1)) {
      for (j in 2:(width - 1)) {
        neighbors <- sum(grid[(i-1):(i+1), (j-1):(j+1)]) - grid[i, j]
        if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
          new_grid[i, j] <- 0
        } else if (grid[i, j] == 0 && neighbors == 3) {
          new_grid[i, j] <- 1
        }
      }
    }
    grid <- new_grid
  }
}

cellular_automata(50, 50)