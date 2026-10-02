update_cell <- function(grid, x, y, width, height) {
  neighbors <- 0
  for (i in max(0, x - 1):min(width, x + 2)) {
    for (j in max(0, y - 1):min(height, y + 2)) {
      if (grid[i + 1, j + 1] == 1) {
        neighbors <- neighbors + 1
      }
    }
  }
  if (grid[x + 1, y + 1] == 1) {
    return(ifelse(2 <= neighbors & neighbors <= 3, 1, 0))
  } else {
    return(ifelse(neighbors == 3, 1, 0))
  }
}

update_grid <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = width, ncol = height)
  for (x in 1:width) {
    for (y in 1:height) {
      new_grid[x, y] <- update_cell(grid, x, y, width, height)
    }
  }
  return(new_grid)
}

main <- function() {
  width <- 10
  height <- 10
  grid <- matrix(ifelse((row(grid) + col(grid)) %% 2, 1, 0), nrow = width, ncol = height)
  while (TRUE) {
    grid <- update_grid(grid, width, height)
  }
}

main()