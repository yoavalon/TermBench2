update_cells <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)])
      neighbors <- neighbors - grid[i, j]
      new_grid[i, j] <- if (neighbors == 3) 1 else grid[i, j]
    }
  }
  return(new_grid)
}

display_grid <- function(grid) {
  for (row in grid) {
    cat(paste(ifelse(row == 1, "O", "."), collapse = " "), "\n")
  }
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  while (TRUE) {
    display_grid(grid)
    grid <- update_cells(grid)
  }
}

main()