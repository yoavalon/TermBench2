cellular_automata <- function() {
  grid <- sample(c(0, 1), 100, replace = TRUE)
  while (TRUE) {
    new_grid <- c()
    for (i in 1:length(grid)) {
      left <- grid[i - 1]
      if (i == 1) left <- grid[length(grid)]
      center <- grid[i]
      right <- grid[i + 1]
      if (i == length(grid)) right <- grid[1]
      new_grid <- c(new_grid, ifelse(left + center + right == 2, 1, 0))
    }
    grid <- new_grid
  }
}

cellular_automata()