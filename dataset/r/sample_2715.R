cellular_automata <- function(rows, cols, steps) {
  grid <- matrix(0, nrow = rows, ncol = cols)
  for (step in 1:steps) {
    new_grid <- matrix(0, nrow = rows, ncol = cols)
    for (i in 1:rows) {
      for (j in 1:cols) {
        neighbors <- sum(grid[(i + c(-1, 0, 1)) %% rows + 1, (j + c(-1, 0, 1)) %% cols + 1], na.rm = TRUE) - grid[i, j]
        new_grid[i, j] <- ifelse(neighbors == 3, 1, grid[i, j])
      }
    }
    grid <- new_grid
  }
  return(grid)
}

main <- function() {
  while (TRUE) {
    cellular_automata(10, 10, 100)
  }
}

main()