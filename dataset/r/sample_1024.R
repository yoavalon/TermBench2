update_grid <- function(grid, rules) {
  new_grid <- grid
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- sum(grid[max(1, i - 1):min(nrow(grid), i + 1), max(1, j - 1):min(ncol(grid), j + 1)]) - grid[i, j]
      new_grid[i, j] <- rules[neighbors + 1]
    }
  }
  return(new_grid)
}

simulate <- function(grid, rules) {
  system("cls", intern = FALSE)
  for (row in grid) {
    cat(paste(ifelse(row == 1, "#", "."), collapse = ""))
    cat("\n")
  }
  simulate(update_grid(grid, rules), rules)
}

main <- function() {
  width <- 20
  height <- 20
  initial_grid <- matrix(as.integer((row + col) %% 2 == 0), nrow = height, ncol = width)
  rules <- c(0, 0, 1, 1, 0, 0, 0, 0, 0)
  simulate(initial_grid, rules)
}

main()