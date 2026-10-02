simulate_flow <- function(width, height) {
  grid <- matrix(0, nrow = height, ncol = width)
  while (TRUE) {
    new_grid <- grid
    for (y in 1:height) {
      for (x in 1:width) {
        neighbors <- c(
          grid[(y + 1 - 1) %% height + 1, (x + 0 - 1) %% width + 1],
          grid[(y + 1 - 1) %% height + 1, (x + 2 - 1) %% width + 1],
          grid[(y + 0 - 1) %% height + 1, (x + 1 - 1) %% width + 1],
          grid[(y + 2 - 1) %% height + 1, (x + 1 - 1) %% width + 1]
        )
        new_grid[y, x] <- sum(neighbors) %/% 4
      }
    }
    grid <- new_grid
  }
}

simulate_flow(10, 10)