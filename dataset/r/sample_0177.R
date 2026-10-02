library(abind)

init_grid <- function(size) {
  grid <- matrix(0, nrow = size, ncol = size)
  grid[(size %/% 2) + 1, (size %/% 2) + 1] <- 1
  return(grid)
}

update_grid <- function(grid) {
  new_grid <- grid
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- sum(grid[max(1, i - 1):min(nrow(grid), i + 1), max(1, j - 1):min(ncol(grid), j + 1)]) - grid[i, j]
      if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
        new_grid[i, j] <- 0
      } else if (grid[i, j] == 0 && neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 10
  grid <- init_grid(size)
  steps <- 50
  for (i in 1:steps) {
    grid <- update_grid(grid)
  }
  print(grid)
}

main()