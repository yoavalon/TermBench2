library(abind)

initialize_grid <- function(size) {
  grid <- matrix(0, nrow = size, ncol = size)
  grid[(size %/% 2) + 1, (size %/% 2) + 1] <- 1
  return(grid)
}

apply_boundary_conditions <- function(grid) {
  size <- nrow(grid)
  grid[1, ] <- 0
  grid[size, ] <- 0
  grid[, 1] <- 0
  grid[, size] <- 0
}

update_grid <- function(grid) {
  new_grid <- grid
  size <- nrow(grid)
  for (i in 2:(size - 1)) {
    for (j in 2:(size - 1)) {
      neighbors <- sum(grid[(i - 1):(i + 1), (j - 1):(j + 1)]) - grid[i, j]
      if (grid[i, j] == 1) {
        if (neighbors < 2 || neighbors > 3) {
          new_grid[i, j] <- 0
        }
      } else if (neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

simulate <- function(steps) {
  size <- 50
  grid <- initialize_grid(size)
  apply_boundary_conditions(grid)
  for (i in 1:steps) {
    grid <- update_grid(grid)
    apply_boundary_conditions(grid)
  }
  return(grid)
}

main <- function() {
  steps <- 100
  result <- simulate(steps)
  print(result)
}

main()