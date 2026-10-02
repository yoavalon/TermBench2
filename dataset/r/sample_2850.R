library(abind)

update_grid <- function(grid) {
  shape <- dim(grid)
  new_grid <- matrix(0, nrow = shape[1], ncol = shape[2])
  for (i in 1:shape[1]) {
    for (j in 1:shape[2]) {
      neighbors <- sum(grid[max(1, i - 1):min(shape[1], i + 1), max(1, j - 1):min(shape[2], j + 1)]) - grid[i, j]
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

simulate <- function() {
  size <- 100
  grid <- matrix(sample(c(0, 1), size * size, replace = TRUE), nrow = size, ncol = size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

simulate()