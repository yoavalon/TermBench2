update_grid <- function(grid) {
  new_grid <- grid
  for (i in 2:nrow(grid) - 1) {
    for (j in 2:ncol(grid) - 1) {
      neighbors <- sum(grid[i-1:i+1, j-1:j+1]) - grid[i, j]
      if (grid[i, j] == 1) {
        new_grid[i, j] <- ifelse(neighbors %in% c(2, 3), 1, 0)
      } else {
        new_grid[i, j] <- ifelse(neighbors == 3, 1, 0)
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid_size <- 50
  grid <- matrix(sample(c(0, 1), grid_size^2, replace = TRUE), nrow = grid_size, ncol = grid_size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()