library(abind)

initialize_grid <- function(size) {
  return(matrix(sample(0:1, size*size, replace=TRUE), nrow=size, ncol=size))
}

evolve <- function(grid) {
  size <- nrow(grid)
  next_grid <- matrix(0, nrow=size, ncol=size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[max(1,i-1):min(size,i+1), max(1,j-1):min(size,j+1)]) - grid[i, j]
      if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
        next_grid[i, j] <- 0
      } else if (grid[i, j] == 0 && neighbors == 3) {
        next_grid[i, j] <- 1
      } else {
        next_grid[i, j] <- grid[i, j]
      }
    }
  }
  return(next_grid)
}

main <- function() {
  grid_size <- 100
  grid <- initialize_grid(grid_size)
  while (TRUE) {
    grid <- evolve(grid)
  }
}

main()