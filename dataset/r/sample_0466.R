update_cell <- function(grid, i, j, size) {
  neighbors <- 0
  for (x in i - 1:i + 1) {
    for (y in j - 1:j + 1) {
      if (x >= 0 && x < size && y >= 0 && y < size && !(x == i && y == j)) {
        neighbors <- neighbors + grid[x + 1, y + 1]
      }
    }
  }
  return(neighbors == 3 || (grid[i + 1, j + 1] && neighbors == 2))
}

step <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      new_grid[i, j] <- update_cell(grid, i - 1, j - 1, size)
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 10
  grid <- matrix(0, nrow = size, ncol = size)
  grid[2, 2] <- 1
  grid[3, 3] <- 1
  grid[3, 2] <- 1
  while (TRUE) {
    grid <- step(grid)
  }
}

main()