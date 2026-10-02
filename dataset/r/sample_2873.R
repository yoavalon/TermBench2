library(abind)

update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i-1):min(rows, i+1), max(1, j-1):min(cols, j+1)]) - grid[i, j]
      new_grid[i, j] <- ifelse(neighbors == 3 | (neighbors == 2 & grid[i, j] == 1), 1, 0)
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- matrix(0, nrow = 50, ncol = 50)
  grid[25, 25] <- 1
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()