initialize_grid <- function(size) {
  matrix(0, nrow = size, ncol = size, byrow = TRUE)
}

update_grid <- function(grid) {
  new_grid <- grid
  rows <- nrow(grid)
  cols <- ncol(grid)
  for (i in 2:(rows - 1)) {
    for (j in 2:(cols - 1)) {
      neighbors <- sum(grid[(i - 1):(i + 1), (j - 1):(j + 1)])
      if (neighbors == 3 || (grid[i, j] == 1 && neighbors == 2)) {
        new_grid[i, j] <- 1
      } else {
        new_grid[i, j] <- 0
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 50
  grid <- initialize_grid(size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()