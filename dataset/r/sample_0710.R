update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)] == 1) - grid[i, j]
      new_grid[i, j] <- ifelse(neighbors == 3 | (grid[i, j] == 1 & neighbors == 2), 1, 0)
    }
  }
  return(new_grid)
}

simulate <- function(grid, steps) {
  for (step in 1:steps) {
    grid <- update_grid(grid)
  }
  return(grid)
}

main <- function() {
  initial_grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  steps <- 5
  final_grid <- simulate(initial_grid, steps)
  for (i in 1:nrow(final_grid)) {
    cat(paste(final_grid[i, ], collapse = " "), "\n")
  }
}

main()