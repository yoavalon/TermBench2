update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- expand.grid(i + c(-1, 0, 1), j + c(-1, 0, 1))
      neighbors <- neighbors[neighbors[, 1] != i | neighbors[, 2] != j, ]
      neighbors <- neighbors[neighbors[, 1] >= 1 & neighbors[, 1] <= nrow(grid) & neighbors[, 2] >= 1 & neighbors[, 2] <= ncol(grid), ]
      live_neighbors <- sum(grid[neighbors[, 1], neighbors[, 2]])
      new_grid[i, j] <- ifelse(live_neighbors == 3 | (grid[i, j] == 1 & live_neighbors == 2), 1, 0)
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  for (i in 1:10) {
    grid <- update_grid(grid)
    print(paste0(apply(grid, 1, function(row) paste0(ifelse(row == 1, 'X', ' '), collapse = '')), collapse = '\n'))
    print()
  }
}

main()