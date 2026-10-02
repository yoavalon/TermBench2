simulate <- function(grid, rules) {
  while (TRUE) {
    new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
    for (i in 1:nrow(grid)) {
      for (j in 1:ncol(grid)) {
        neighbors <- numeric(0)
        for (dx in -1:1) {
          for (dy in -1:1) {
            if (i + dx > 0 && i + dx <= nrow(grid) && j + dy > 0 && j + dy <= ncol(grid)) {
              neighbors <- c(neighbors, grid[i + dx, j + dy])
            } else {
              neighbors <- c(neighbors, 0)
            }
          }
        }
        new_grid[i, j] <- rules[sum(neighbors) + 1]
      }
    }
    grid <- new_grid
  }
}

main <- function() {
  initial_grid <- matrix(c(0, 1, 0, 0, 0, 1, 1, 1, 1), nrow = 3, byrow = TRUE)
  transition_rules <- c(0, 1, 1, 1, 0, 0, 0, 0, 0)
  simulate(initial_grid, transition_rules)
}

main()