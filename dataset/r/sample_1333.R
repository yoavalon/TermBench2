library(abind)

update_grid <- function(grid) {
  new_grid <- grid
  for (i in 2:(dim(grid)[1] - 1)) {
    for (j in 2:(dim(grid)[2] - 1)) {
      neighbors <- sum(grid[i-1:i+1, j-1:j+1]) - grid[i, j]
      if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
        new_grid[i, j] <- 0
      } else if (grid[i, j] == 0 && neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

simulate <- function(grid, steps) {
  for (step in 1:steps) {
    grid <- update_grid(grid)
  }
  return(grid)
}

main <- function() {
  size <- 50
  grid <- matrix(0, nrow = size, ncol = size)
  grid[20:25, 20:25] <- sample(0:1, size = 25, replace = TRUE)
  final_grid <- simulate(grid, 100)
  print(final_grid)
}

main()