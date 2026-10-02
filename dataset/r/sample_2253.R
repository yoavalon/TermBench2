update_state <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- sum(grid[max(1, i - 1):min(nrow(grid), i + 1), max(1, j - 1):min(ncol(grid), j + 1)], na.rm = TRUE) - grid[i, j]
      new_grid[i, j] <- if (neighbors == 3) 1 else if (neighbors < 2 | neighbors > 3) 0 else grid[i, j]
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 1, 1, 1, 0, 1, 0), nrow = 3, byrow = TRUE)
  while (TRUE) {
    grid <- update_state(grid)
    for (row in 1:nrow(grid)) {
      cat(paste(grid[row, ], collapse = " "), "\n")
    }
    cat(rep("-", ncol(grid) * 2), "\n")
  }
}

main()