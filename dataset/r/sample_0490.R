update_grid <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- sum(grid[(y + seq(-1, 1) - 1) %% height + 1, (x + seq(-1, 1) - 1) %% width + 1])
      if (grid[y, x] == 1) {
        new_grid[y, x] <- ifelse(neighbors %in% c(2, 3), 1, 0)
      } else {
        new_grid[y, x] <- ifelse(neighbors == 3, 1, 0)
      }
    }
  }
  return(new_grid)
}

main <- function() {
  width <- 50
  height <- 50
  grid <- matrix(ifelse((seq_len(width) + seq_len(height) - 1) %% 2 == 0, 1, 0), nrow = height, ncol = width)
  while (TRUE) {
    grid <- update_grid(grid, width, height)
  }
}

main()