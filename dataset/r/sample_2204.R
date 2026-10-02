update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0.0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      total <- 0.0
      for (di in -1:1) {
        for (dj in -1:1) {
          ni <- i + di
          nj <- j + dj
          if (ni >= 1 && ni <= rows && nj >= 1 && nj <= cols) {
            total <- total + grid[ni, nj]
          }
        }
      }
      new_grid[i, j] <- total / 9.0
    }
  }
  return(new_grid)
}

simulate <- function() {
  grid <- outer(0:9, 0:9, "+")
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

simulate()