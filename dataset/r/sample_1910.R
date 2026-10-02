library(abind)

update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols, type = "float32")
  for (i in 2:(rows - 1)) {
    for (j in 2:(cols - 1)) {
      neighbors <- grid[(i - 1):(i + 1), (j - 1):(j + 1)]
      new_grid[i, j] <- sum(neighbors) - grid[i, j]
    }
  }
  return(new_grid)
}

simulate_flow <- function(iterations) {
  grid <- matrix(runif(100), nrow = 10, ncol = 10, type = "float32")
  for (i in 1:iterations) {
    grid <- update_grid(grid)
  }
  return(grid)
}

main <- function() {
  result <- simulate_flow(100)
  print(result)
}

main()