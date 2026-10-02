initialize_grid <- function(size) {
  grid <- matrix(0, nrow = size, ncol = size)
  grid[(size %/% 2) + 1, (size %/% 2) + 1] <- 1
  return(grid)
}

update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- sum(grid[max(1, i - 1):min(nrow(grid), i + 1), max(1, j - 1):min(ncol(grid), j + 1)], na.rm = TRUE) - grid[i, j]
      if (neighbors == 3 || (grid[i, j] == 1 && neighbors == 2)) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid_size <- 10
  grid <- initialize_grid(grid_size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()