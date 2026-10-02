initialize_grid <- function(size) {
  grid <- matrix(0, nrow = size, ncol = size)
  grid[(size %/% 2) + 1, (size %/% 2) + 1] <- 1
  return(grid)
}

update_grid <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[max(1, i - 1):min(size, i + 1), max(1, j - 1):min(size, j + 1)])
      if (neighbors == 3 || (grid[i, j] == 1 && neighbors == 2)) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 10
  grid <- initialize_grid(size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()