update_grid <- function(grid, rules) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- c()
      for (x in max(1, i - 1):min(nrow(grid), i + 1)) {
        for (y in max(1, j - 1):min(ncol(grid), j + 1)) {
          if (!(x == i && y == j)) {
            neighbors <- c(neighbors, grid[x, y])
          }
        }
      }
      neighbors_sorted <- sort(neighbors)
      neighbors_tuple <- paste(neighbors_sorted, collapse = ",")
      if (!is.null(rules[[neighbors_tuple]])) {
        new_grid[i, j] <- rules[[neighbors_tuple]]
      } else {
        new_grid[i, j] <- 0
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 1, 0, 1, 0, 1, 0), nrow = 3, byrow = TRUE)
  rules <- list(`0,0,0,0,0,0,0,0` = 0, `1,1,1,1,1,1,1,1` = 1, `0,0,0,1,1,1,0,0` = 1)
  while (TRUE) {
    grid <- update_grid(grid, rules)
  }
}

main()