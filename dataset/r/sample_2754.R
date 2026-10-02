r
cellular_automata <- function(n, m) {
  grid <- matrix(0, n, m)
  while (TRUE) {
    new_grid <- matrix(0, n, m)
    for (i in 1:n) {
      for (j in 1:m) {
        state <- grid[i, j]
        neighbors <- sum(grid[max(1, i-1):min(n, i+1), max(1, j-1):min(m, j+1)]) - state
        new_grid[i, j] <- ifelse(neighbors == 3 || (state && neighbors == 2), 1, 0)
      }
    }
    grid <- new_grid
  }
}

main <- function() {
  cellular_automata(10, 10)
}

main()