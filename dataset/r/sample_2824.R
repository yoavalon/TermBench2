init_grid <- function(rows, cols) {
  grid <- matrix(0, nrow = rows, ncol = cols)
  grid[(rows %/% 2) + 1, (cols %/% 2) + 1] <- 1
  return(grid)
}

update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(c(grid[max(1, i-1), j], grid[min(rows, i+1), j], grid[i, max(1, j-1)], grid[i, min(cols, j+1)]))
      new_grid[i, j] <- ifelse(neighbors == 1, 1, 0)
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- init_grid(10, 10)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()