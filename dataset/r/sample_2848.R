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
      neighbors <- sum(grid[max(1, i - 1):min(size, i + 1), max(1, j - 1):min(size, j + 1)], na.rm = TRUE) - grid[i, j]
      new_grid[i, j] <- ifelse(neighbors == 3, 1, 0)
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