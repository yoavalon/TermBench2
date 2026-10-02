update_grid <- function(grid) {
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
      new_grid[i, j] <- sum(neighbors) %/% 2
    }
  }
  return(new_grid)
}

simulate <- function(grid) {
  while (TRUE) {
    grid <- update_grid(grid)
    for (row in grid) {
      cat(paste(row, collapse = " "), "\n")
    }
    cat("\n")
  }
}

main <- function() {
  initial_grid <- matrix(c(1, 0, 1, 0, 1, 0, 1, 0, 1), nrow = 3, byrow = TRUE)
  simulate(initial_grid)
}

main()