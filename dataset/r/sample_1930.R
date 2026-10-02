library(abind)

update_grid <- function(grid, precision) {
  size <- nrow(grid)
  new_grid <- matrix(0, size, size)
  for (i in 2:(size - 1)) {
    for (j in 2:(size - 1)) {
      avg <- mean(grid[(i - 1):(i + 1), (j - 1):(j + 1)])
      new_grid[i, j] <- round(avg, precision)
    }
  }
  return(new_grid)
}

run_simulation <- function(steps, precision) {
  grid_size <- 10
  grid <- matrix(runif(grid_size * grid_size), grid_size, grid_size)
  for (i in 1:steps) {
    grid <- update_grid(grid, precision)
  }
  return(grid)
}

if (identical(main, TRUE)) {
  steps <- 50
  precision <- 3
  result <- run_simulation(steps, precision)
  print(result)
}