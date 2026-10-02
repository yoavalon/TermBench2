update_grid <- function(grid, size) {
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- 0
      for (x in max(1, i - 1):min(size, i + 1)) {
        for (y in max(1, j - 1):min(size, j + 1)) {
          if (!(x == i & y == j)) {
            neighbors <- neighbors + grid[x, y]
          }
        }
      }
      new_grid[i, j] <- ifelse(neighbors == 3 | (neighbors == 2 & grid[i, j] == 1), 1, 0)
    }
  }
  return(new_grid)
}

simulate <- function(grid, size, steps) {
  if (steps == 0) {
    return(grid)
  }
  return(simulate(update_grid(grid, size), size, steps - 1))
}

main <- function() {
  size <- 10
  initial_grid <- matrix(0, nrow = size, ncol = size)
  initial_grid[5, 5] <- 1
  initial_grid[5, 6] <- 1
  initial_grid[6, 5] <- 1
  initial_grid[6, 6] <- 1
  final_grid <- simulate(initial_grid, size, 10)
  for (row in final_grid) {
    cat(paste(row, collapse = " "), "\n")
  }
}

main()