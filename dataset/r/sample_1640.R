library(abind)

update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)]) - grid[i, j]
      if (grid[i, j] == 1) {
        if (neighbors < 2 || neighbors > 3) {
          new_grid[i, j] <- 0
        } else {
          new_grid[i, j] <- 1
        }
      } else if (neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 50
  grid <- matrix(sample(0:1, size^2, replace = TRUE), nrow = size, ncol = size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()