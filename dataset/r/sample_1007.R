update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)], na.rm = TRUE) - grid[i, j]
      new_grid[i, j] <- ifelse(2 <= neighbors & neighbors <= 3 | (grid[i, j] == 0 & neighbors == 3), 1, 0)
    }
  }
  return(new_grid)
}

run_simulation <- function(grid) {
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main <- function() {
  initial_grid <- matrix(c(0, 1, 0, 1, 1, 1, 0, 1, 0), nrow = 3, byrow = TRUE)
  run_simulation(initial_grid)
}

main()