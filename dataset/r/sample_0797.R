r
update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      count <- sum(grid[max(1, i-1):min(nrow(grid), i+1), max(1, j-1):min(ncol(grid), j+1)], na.rm = TRUE) - grid[i, j]
      new_grid[i, j] <- if (grid[i, j] && count %in% c(2, 3)) 1 else count == 3
    }
  }
  return(new_grid)
}

simulate <- function(grid, steps) {
  for (i in 1:steps) {
    grid <- update_grid(grid)
  }
  return(grid)
}

main <- function() {
  initial_grid <- matrix(c(0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0), nrow = 5, byrow = TRUE)
  final_grid <- simulate(initial_grid, 10)
  for (i in 1:nrow(final_grid)) {
    print(final_grid[i, ])
  }
}

main()