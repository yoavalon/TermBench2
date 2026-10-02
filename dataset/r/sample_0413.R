initialize_grid <- function(rows, cols) {
  return(matrix(0, nrow = rows, ncol = cols))
}

update_grid <- function(grid) {
  new_grid <- grid
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- sum(grid[max(1, i-1):min(nrow(grid), i+1), max(1, j-1):min(ncol(grid), j+1)], na.rm = TRUE) - grid[i, j]
      new_grid[i, j] <- if (neighbors == 3) 1 else if (neighbors < 2 || neighbors > 3) 0 else grid[i, j]
    }
  }
  return(new_grid)
}

main <- function() {
  rows <- 50
  cols <- 50
  grid <- initialize_grid(rows, cols)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()