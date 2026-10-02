update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- sum(grid[max(1, i-1):min(nrow(grid), i+1), max(1, j-1):min(ncol(grid), j+1)] == 1) - grid[i, j]
      new_grid[i, j] <- ifelse(neighbors == 3 || (grid[i, j] == 1 && neighbors == 2), 1, 0)
    }
  }
  return(new_grid)
}

cellular_automata <- function() {
  grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  while (TRUE) {
    grid <- update_grid(grid)
    for (row in grid) {
      cat(paste(row, collapse = " "), "\n")
    }
    cat("\n")
  }
}

cellular_automata()