update_grid <- function(grid, width, height) {
  new_grid <- matrix(0.0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- c()
      for (dy in c(-1, 0, 1)) {
        for (dx in c(-1, 0, 1)) {
          if (dy != 0 || dx != 0) {
            neighbors <- c(neighbors, grid[(y + dy) %% height + 1, (x + dx) %% width + 1])
          }
        }
      }
      new_grid[y, x] <- mean(neighbors)
    }
  }
  return(new_grid)
}

simulate <- function(width, height, steps) {
  grid <- outer(0:(width-1), 0:(height-1), "+")
  for (i in 1:steps) {
    grid <- update_grid(grid, width, height)
  }
  return(grid)
}

main <- function() {
  width <- 10
  height <- 10
  steps <- 5
  final_grid <- simulate(width, height, steps)
  for (i in 1:nrow(final_grid)) {
    print(final_grid[i, ])
  }
}

main()