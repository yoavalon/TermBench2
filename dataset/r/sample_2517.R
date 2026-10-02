update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- 0
      for (di in -1:1) {
        for (dj in -1:1) {
          if (di == 0 && dj == 0) {
            next
          }
          ni <- i + di
          nj <- j + dj
          if (ni >= 1 && ni <= nrow(grid) && nj >= 1 && nj <= ncol(grid)) {
            neighbors <- neighbors + grid[ni, nj]
          }
        }
      }
      if (grid[i, j] == 1) {
        new_grid[i, j] <- ifelse(2 <= neighbors && neighbors <= 3, 1, 0)
      } else {
        new_grid[i, j] <- ifelse(neighbors == 3, 1, 0)
      }
    }
  }
  return(new_grid)
}

main <- function() {
  initial_grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  for (i in 1:10) {
    initial_grid <- update_grid(initial_grid)
    for (row in 1:nrow(initial_grid)) {
      cat(paste(ifelse(initial_grid[row, ] == 1, "#", " "), collapse = ""), "\n")
    }
    cat("\n")
  }
}

main()