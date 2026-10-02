update_grid <- function(grid) {
  new_grid <- grid
  rows <- nrow(grid)
  cols <- ncol(grid)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)]) - grid[i, j]
      if (grid[i, j] == 1) {
        new_grid[i, j] <- ifelse(2 <= neighbors & neighbors <= 3, 1, 0)
      } else {
        new_grid[i, j] <- ifelse(neighbors == 3, 1, 0)
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid_size <- 10
  grid <- matrix(0, nrow = grid_size, ncol = grid_size)
  grid[grid_size %/% 2, grid_size %/% 2] <- 1
  steps <- 50
  for (i in 1:steps) {
    grid <- update_grid(grid)
  }
  print(grid)
}

main()