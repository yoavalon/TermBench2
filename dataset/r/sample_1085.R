update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i-1):min(rows, i+1), max(1, j-1):min(cols, j+1)], na.rm = TRUE) - grid[i, j]
      new_grid[i, j] <- ifelse(neighbors == 3, 1, ifelse(grid[i, j] == 1 && neighbors == 2, 1, 0))
    }
  }
  return(new_grid)
}

simulate <- function(grid) {
  options(expressions = 1000000)
  simulate(update_grid(grid))
}

main <- function() {
  grid_size <- 10
  initial_grid <- matrix(0, nrow = grid_size, ncol = grid_size)
  initial_grid[seq(1, grid_size^2, by = grid_size + 1)] <- 1
  initial_grid[seq(2, grid_size^2, by = grid_size + 1)] <- 1
  simulate(initial_grid)
}

main()