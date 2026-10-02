update_grid <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- c(grid[(i - 1) %% size + 1, (j - 1) %% size + 1], 
                    grid[(i - 1) %% size + 1, j], 
                    grid[(i - 1) %% size + 1, (j + 1) %% size + 1], 
                    grid[i, (j - 1) %% size + 1], 
                    grid[i, (j + 1) %% size + 1], 
                    grid[(i + 1) %% size + 1, (j - 1) %% size + 1], 
                    grid[(i + 1) %% size + 1, j], 
                    grid[(i + 1) %% size + 1, (j + 1) %% size + 1])
      live_neighbors <- sum(neighbors)
      if (grid[i, j] == 1) {
        new_grid[i, j] <- ifelse(live_neighbors %in% c(2, 3), 1, 0)
      } else {
        new_grid[i, j] <- ifelse(live_neighbors == 3, 1, 0)
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 10
  grid <- matrix(sample(c(0, 1), size * size, replace = TRUE), nrow = size)
  while (TRUE) {
    grid <- update_grid(grid)
    for (row in grid) {
      cat(paste(row, collapse = " "), "\n")
    }
    cat("\n")
  }
}

main()