library(abind)

update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)])
      if (grid[i, j] == 1 && neighbors %in% c(3, 4)) {
        new_grid[i, j] <- 1
      } else if (grid[i, j] == 0 && neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid_size <- 50
  grid <- sample(0:1, size = c(grid_size, grid_size), replace = TRUE)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()