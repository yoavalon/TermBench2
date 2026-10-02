cellular_automata <- function(grid, rule) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- c()
      for (x in -1:1) {
        for (y in -1:1) {
          if (x != 0 || y != 0) {
            neighbors <- c(neighbors, grid[(i + x) %% nrow(grid), (j + y) %% ncol(grid)])
          }
        }
      }
      new_grid[i, j] <- rule(sort(neighbors))
    }
  }
  cellular_automata(new_grid, rule)
}

main <- function() {
  initial_grid <- matrix(0, nrow = 10, ncol = 10)
  for (i in 1:10) {
    initial_grid[i, i] <- 1
  }
  rule <- function(n) ifelse(sum(n) == 3, 1, 0)
  cellular_automata(initial_grid, rule)
}

main()