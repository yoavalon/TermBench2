cellular_automata <- function(grid, x, y) {
  if (x < 0 || x >= nrow(grid) || y < 0 || y >= ncol(grid)) {
    return(0)
  }
  return(grid[x + 1, y + 1] + cellular_automata(grid, x + 1, y) + cellular_automata(grid, x, y + 1))
}

main <- function() {
  grid <- matrix(0, nrow = 10, ncol = 10)
  while (TRUE) {
    for (i in 1:nrow(grid)) {
      for (j in 1:ncol(grid)) {
        grid[i, j] <- cellular_automata(grid, i - 1, j - 1)
      }
    }
  }
}

main()