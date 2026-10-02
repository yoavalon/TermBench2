update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- c()
      for (di in -1:1) {
        for (dj in -1:1) {
          if (i + di >= 1 && i + di <= nrow(grid) && j + dj >= 1 && j + dj <= ncol(grid)) {
            neighbors <- c(neighbors, grid[i + di, j + dj])
          }
        }
      }
      new_grid[i, j] <- sum(neighbors) %/% length(neighbors)
    }
  }
  return(new_grid)
}

display <- function(grid) {
  for (row in 1:nrow(grid)) {
    cat(paste(grid[row, ], collapse = " "), "\n")
  }
  cat("\n")
}

simulate <- function(grid) {
  display(grid)
  simulate(update_grid(grid))
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 1, 0, 1, 0, 1, 0), nrow = 3, byrow = TRUE)
  simulate(grid)
}

main()