update_state <- function(grid) {
  new_grid <- matrix(0.0, nrow = nrow(grid), ncol = ncol(grid))
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
      new_grid[i, j] <- neighbors / 9.0
    }
  }
  return(new_grid)
}

run_simulation <- function(steps, size) {
  grid <- matrix(ifelse(seq_along(grid) %% (size + 1) == 0, 1, 0), nrow = size, ncol = size)
  for (step in 1:steps) {
    grid <- update_state(grid)
  }
  return(grid)
}

result <- run_simulation(10, 5)
for (row in result) {
  print(row)
}