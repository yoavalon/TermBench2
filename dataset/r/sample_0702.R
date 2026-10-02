update_grid <- function(grid, size) {
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[max(1, i - 1):min(size, i + 1), max(1, j - 1):min(size, j + 1)], na.rm = TRUE) - grid[i, j]
      new_grid[i, j] <- ifelse(neighbors == 3, 1, ifelse(neighbors == 2, grid[i, j], 0))
    }
  }
  return(new_grid)
}

simulate <- function(size, steps) {
  grid <- matrix(ifelse(row(1:size) %% 2 == 0, 1, 0), nrow = size, ncol = size)
  for (step in 1:steps) {
    grid <- update_grid(grid, size)
  }
  return(grid)
}

main <- function() {
  size <- 5
  steps <- 10
  result <- simulate(size, steps)
  for (row in 1:nrow(result)) {
    cat(paste(result[row, ], collapse = " "), "\n")
  }
}

main()