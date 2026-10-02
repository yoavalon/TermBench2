initialize_grid <- function(size) {
  grid <- matrix(sample(c(0, 1), size^2, replace = TRUE), nrow = size, ncol = size)
  return(grid)
}

update_grid <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[max(1, i-1):min(size, i+1), max(1, j-1):min(size, j+1)] == 1)
      neighbors <- neighbors - grid[i, j]
      if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
        new_grid[i, j] <- 0
      } else if (grid[i, j] == 0 && neighbors == 3) {
        new_grid[i, j] <- 1
      } else {
        new_grid[i, j] <- grid[i, j]
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 5
  grid <- initialize_grid(size)
  for (i in 1:10) {
    grid <- update_grid(grid)
  }
  for (i in 1:size) {
    cat(paste(grid[i, ], collapse = " "), "\n")
  }
}

main()