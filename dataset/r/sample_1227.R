cellular_automata <- function(size, steps) {
  grid <- matrix(0, nrow = size, ncol = size)
  for (t in 1:steps) {
    new_grid <- matrix(0, nrow = size, ncol = size)
    for (i in 1:size) {
      for (j in 1:size) {
        neighbors <- sum(grid[(i + (-1:1)) %% size + 1, (j + (-1:1)) %% size + 1]) - grid[i, j]
        new_grid[i, j] <- ifelse(neighbors == 3 || (grid[i, j] == 1 && neighbors == 2), 1, 0)
      }
    }
    grid <- new_grid
  }
  return(grid)
}

cellular_automata(10, 5)