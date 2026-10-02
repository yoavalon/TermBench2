update_state <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0.0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- cbind(c(i - 1, i + 1, i, i), c(j, j, j - 1, j + 1))
      valid_neighbors <- neighbors[neighbors[, 1] >= 1 & neighbors[, 1] <= rows & neighbors[, 2] >= 1 & neighbors[, 2] <= cols, ]
      value <- sum(grid[valid_neighbors[, 1], valid_neighbors[, 2]])
      new_grid[i, j] <- value / 4.0
    }
  }
  return(new_grid)
}

simulate <- function(grid) {
  while (TRUE) {
    grid <- update_state(grid)
  }
}

main <- function() {
  grid_size <- 10
  initial_grid <- outer(0:(grid_size - 1), 0:(grid_size - 1), FUN = "*")
  simulate(initial_grid)
}

main()