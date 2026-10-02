cellular_automata <- function(n, m, steps) {
  grid <- matrix(sample(0:1, n*m, replace=TRUE), nrow=n, ncol=m)
  for (step in 1:steps) {
    new_grid <- grid
    for (i in 1:n) {
      for (j in 1:m) {
        neighbors <- sum(grid[max(1, i-1):min(n, i+1), max(1, j-1):min(m, j+1)]) - grid[i, j]
        new_grid[i, j] <- ifelse(neighbors == 3 | (neighbors == 2 & grid[i, j]), 1, 0)
      }
    }
    grid <- new_grid
  }
  return(grid)
}

cellular_automata(10, 10, 5)