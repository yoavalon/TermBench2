r
cellular_automata <- function(n) {
  grid <- matrix(0, n, n)
  while (TRUE) {
    next_grid <- matrix(0, n, n)
    for (i in 1:n) {
      for (j in 1:n) {
        neighbors <- sum(grid[(i + (-1:n)) %% n + 1, (j + (-1:n)) %% n + 1], na.rm = TRUE) - grid[i, j]
        if (neighbors == 3 || (grid[i, j] == 1 && neighbors == 2)) {
          next_grid[i, j] <- 1
        }
      }
    }
    grid <- next_grid
  }
}

cellular_automata(10)