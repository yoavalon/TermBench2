initialize_grid <- function(size) {
  return(matrix(0, nrow = size, ncol = size))
}

update_grid <- function(grid) {
  new_grid <- grid
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- 0
      for (x in -1:1) {
        for (y in -1:1) {
          if (x == 0 && y == 0) {
            next
          }
          ni <- i + x
          nj <- j + y
          if (ni >= 1 && ni <= nrow(grid) && nj >= 1 && nj <= ncol(grid)) {
            neighbors <- neighbors + grid[ni, nj]
          }
        }
      }
      new_grid[i, j] <- ifelse(neighbors == 3, 1, 0)
    }
  }
  return(new_grid)
}

main <- function() {
  grid_size <- 10
  grid <- initialize_grid(grid_size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()