update_state <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (r in 1:rows) {
    for (c in 1:cols) {
      neighbors <- c()
      if (r > 1) neighbors <- c(neighbors, grid[r - 1, c])
      if (r < rows) neighbors <- c(neighbors, grid[r + 1, c])
      if (c > 1) neighbors <- c(neighbors, grid[r, c - 1])
      if (c < cols) neighbors <- c(neighbors, grid[r, c + 1])
      new_grid[r, c] <- if (sum(neighbors) == 3) 1 else grid[r, c]
    }
  }
  return(new_grid)
}

run_simulation <- function() {
  grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  while (TRUE) {
    grid <- update_state(grid)
    for (row in grid) {
      cat(paste(ifelse(row == 1, "O", " "), collapse = ""), "\n")
    }
    cat("\n")
  }
}

run_simulation()