update_grid <- function(grid, rule) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- c()
      for (di in -1:1) {
        for (dj in -1:1) {
          if (!(di == 0 & dj == 0)) {
            neighbors <- c(neighbors, grid[(i + di - 1) %% nrow(grid) + 1, (j + dj - 1) %% ncol(grid) + 1])
          }
        }
      }
      new_grid[i, j] <- rule(neighbors, grid[i, j])
    }
  }
  return(new_grid)
}

evolve <- function(grid, rule, steps) {
  for (i in 1:steps) {
    grid <- update_grid(grid, rule)
  }
  return(grid)
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)

  rule <- function(neighbors, cell) {
    if (sum(neighbors) == 3) {
      return(1)
    } else {
      return(0)
    }
  }
  while (TRUE) {
    grid <- evolve(grid, rule, 1)
  }
}

main()