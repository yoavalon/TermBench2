update_cell <- function(state, neighbors) {
  active_neighbors <- sum(neighbors)
  if (state == 1) {
    return(ifelse(active_neighbors %in% c(2, 3), 1, 0))
  } else {
    return(ifelse(active_neighbors == 3, 1, 0))
  }
}

simulate <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- c()
      for (x in c(-1, 0, 1)) {
        for (y in c(-1, 0, 1)) {
          if (x == 0 & y == 0) {
            next
          }
          ni <- i + x
          nj <- j + y
          if (ni >= 1 & ni <= rows & nj >= 1 & nj <= cols) {
            neighbors <- c(neighbors, grid[ni, nj])
          }
        }
      }
      new_grid[i, j] <- update_cell(grid[i, j], neighbors)
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), nrow = 5, byrow = TRUE)
  while (TRUE) {
    grid <- simulate(grid)
  }
}

main()