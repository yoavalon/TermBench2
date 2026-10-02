library(abind)

initialize_grid <- function(size) {
  return(matrix(0, nrow = size, ncol = size))
}

update_grid <- function(grid) {
  new_grid <- grid
  rows <- nrow(grid)
  cols <- ncol(grid)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)]) - grid[i, j]
      if (grid[i, j] == 0 && neighbors == 3) {
        new_grid[i, j] <- 1
      } else if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
        new_grid[i, j] <- 0
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid_size <- 50
  iterations <- 100
  grid <- initialize_grid(grid_size)
  for (i in 1:iterations) {
    grid <- update_grid(grid)
  }
  print(grid)
}

main()