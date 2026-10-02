r
update_state <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- c(grid[(i - 1) %% nrow(grid), (j - 1) %% ncol(grid)], 
                    grid[(i - 1) %% nrow(grid), j], 
                    grid[(i - 1) %% nrow(grid), (j + 1) %% ncol(grid)], 
                    grid[i, (j - 1) %% ncol(grid)], 
                    grid[i, (j + 1) %% ncol(grid)], 
                    grid[(i + 1) %% nrow(grid), (j - 1) %% ncol(grid)], 
                    grid[(i + 1) %% nrow(grid), j], 
                    grid[(i + 1) %% nrow(grid), (j + 1) %% ncol(grid)])
      live_neighbors <- sum(neighbors)
      if (grid[i, j] == 1) {
        if (live_neighbors < 2 | live_neighbors > 3) {
          new_grid[i, j] <- 0
        } else {
          new_grid[i, j] <- 1
        }
      } else if (live_neighbors == 3) {
        new_grid[i, j] <- 1
      } else {
        new_grid[i, j] <- 0
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), nrow = 5, byrow = TRUE)
  while (TRUE) {
    grid <- update_state(grid)
    for (row in grid) {
      cat(paste(row, collapse = " "), "\n")
    }
    cat("\n")
  }
}

main()