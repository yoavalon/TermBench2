update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- 0
      for (x in max(1, i - 1):min(rows, i + 1)) {
        for (y in max(1, j - 1):min(cols, j + 1)) {
          if (!(x == i & y == j) & grid[x, y] == 1) {
            neighbors <- neighbors + 1
          }
        }
      }
      new_grid[i, j] <- ifelse(neighbors == 3 | (neighbors == 2 & grid[i, j] == 1), 1, 0)
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  while (TRUE) {
    grid <- update_grid(grid)
    for (row in grid) {
      cat(paste(ifelse(row == 1, 'O', '.'), collapse = ' '), '\n')
    }
    cat('\n')
  }
}

main()