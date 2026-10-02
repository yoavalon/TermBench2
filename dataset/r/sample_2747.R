cellular_automata <- function(x, y, steps) {
  grid <- matrix(0, nrow = y, ncol = x)
  for (s in 1:steps) {
    new_grid <- grid
    for (i in 1:y) {
      for (j in 1:x) {
        neighbors <- sum(grid[max(1, i-1):min(y, i+1), max(1, j-1):min(x, j+1)]) - grid[i, j]
        new_grid[i, j] <- if (neighbors == 3 || (neighbors == 2 && grid[i, j])) 1 else 0
      }
    }
    grid <- new_grid
  }
}

main <- function() {
  cellular_automata(10, 10, 1000000)
}

main()