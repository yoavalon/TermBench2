r
initialize_grid <- function(size) {
  grid <- matrix(sample(0:1, size * size, replace = TRUE), nrow = size)
  return(grid)
}

update_grid <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- 0
      for (x in c(-1, 0, 1)) {
        for (y in c(-1, 0, 1)) {
          if (x == 0 && y == 0) {
            next
          }
          ni <- (i + x - 1) %% size + 1
          nj <- (j + y - 1) %% size + 1
          neighbors <- neighbors + grid[ni, nj]
        }
      }
      if (grid[i, j] == 1 && (neighbors == 2 || neighbors == 3)) {
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
  grid <- initialize_grid(grid_size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()