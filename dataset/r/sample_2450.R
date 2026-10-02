simulate_cells <- function(rows, cols, steps) {
  grid <- matrix(0, nrow = rows, ncol = cols)
  for (step in 1:steps) {
    new_grid <- matrix(0, nrow = rows, ncol = cols)
    for (i in 1:rows) {
      for (j in 1:cols) {
        neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)], na.rm = TRUE) - grid[i, j]
        if (neighbors == 3 || (grid[i, j] == 1 && neighbors == 2)) {
          new_grid[i, j] <- 1
        }
      }
    }
    grid <- new_grid
  }
  return(grid)
}

simulate_cells(10, 10, 5)