update_grid <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- sum(grid[(y + c(-1, -1, -1, 0, 0, 1, 1, 1)) %% height + 1, (x + c(-1, 0, 1, -1, 1, -1, 0, 1)) %% width + 1])
      if (grid[y, x] == 1 & (neighbors < 2 | neighbors > 3)) {
        new_grid[y, x] <- 0
      } else if (grid[y, x] == 0 & neighbors == 3) {
        new_grid[y, x] <- 1
      } else {
        new_grid[y, x] <- grid[y, x]
      }
    }
  }
  return(new_grid)
}

main <- function() {
  width <- 10
  height <- 10
  grid <- matrix(as.integer((row(1:height) + col(1:width)) %% 2), nrow = height, ncol = width)
  while (TRUE) {
    grid <- update_grid(grid, width, height)
  }
}

main()