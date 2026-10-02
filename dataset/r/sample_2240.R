update_grid <- function(grid, width, height) {
  new_grid <- matrix(0.0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- 0
      for (i in -1:1) {
        for (j in -1:1) {
          if (i == 0 && j == 0) {
            next
          }
          nx <- (x + i) %% width
          ny <- (y + j) %% height
          neighbors <- neighbors + grid[ny, nx]
        }
      }
      new_grid[y, x] <- neighbors / 9
    }
  }
  return(new_grid)
}

simulate <- function(width, height) {
  grid <- matrix(0.0, nrow = height, ncol = width)
  while (TRUE) {
    grid <- update_grid(grid, width, height)
  }
}

main <- function() {
  simulate(100, 100)
}

main()