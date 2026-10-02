cellular_automata <- function(grid, steps) {
  if (steps == 0) {
    return(grid)
  }
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- sum(grid[x, y] for (x, y) in cbind(c(i - 1, i + 1, i, i), c(j, j, j - 1, j + 1)) if x >= 1 & x <= nrow(grid) & y >= 1 & y <= ncol(grid))
      new_grid[i, j] <- ifelse(neighbors == 3 | (grid[i, j] == 1 & neighbors == 2), 1, 0)
    }
  }
  return(cellular_automata(new_grid, steps - 1))
}

grid <- matrix(c(0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0), nrow = 5, byrow = TRUE)
result <- cellular_automata(grid, 10)
for (row in result) {
  print(row)
}