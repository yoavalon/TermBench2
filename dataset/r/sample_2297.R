init_grid <- function(size) {
  matrix(0.0, nrow = size, ncol = size)
}

update_grid <- function(grid, diffusion_rate) {
  size <- nrow(grid)
  new_grid <- init_grid(size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- 0.0
      for (di in -1:1) {
        for (dj in -1:1) {
          if (di == 0 && dj == 0) {
            next
          }
          ni <- i + di
          nj <- j + dj
          if (ni >= 1 && ni <= size && nj >= 1 && nj <= size) {
            neighbors <- neighbors + grid[ni, nj]
          }
        }
      }
      new_grid[i, j] <- grid[i, j] + diffusion_rate * neighbors
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 100
  diffusion_rate <- 0.01
  grid <- init_grid(size)
  while (TRUE) {
    grid <- update_grid(grid, diffusion_rate)
  }
}

main()