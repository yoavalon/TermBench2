library(abind)

update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(i - 1, 1):min(i + 1, rows), max(j - 1, 1):min(j + 1, cols)]) - grid[i, j]
      if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
        new_grid[i, j] <- 0
      } else if (grid[i, j] == 0 && neighbors == 3) {
        new_grid[i, j] <- 1
      } else {
        new_grid[i, j] <- grid[i, j]
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 10
  grid <- matrix(sample(c(0, 1), size^2, replace = TRUE), nrow = size, ncol = size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()