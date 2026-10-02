update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
  for (i in 1:nrow(grid)) {
    for (j in 1:ncol(grid)) {
      neighbors <- expand.grid(x = i + c(-1, 0, 1), y = j + c(-1, 0, 1))
      neighbors <- neighbors[!(neighbors$x == i & neighbors$y == j), ]
      live_neighbors <- sum(grid[neighbors$x, neighbors$y], na.rm = TRUE)
      if (grid[i, j] == 1 & live_neighbors %in% c(2, 3)) {
        new_grid[i, j] <- 1
      } else if (grid[i, j] == 0 & live_neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

simulate <- function(grid) {
  display(grid)
  simulate(update_grid(grid))
}

display <- function(grid) {
  cat(paste0(apply(grid, 1, function(row) {
    paste0(ifelse(row == 1, "█", " "), collapse = "")
  }), collapse = "\n"), "\n")
}

main <- function() {
  initial_grid <- matrix(c(0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0), nrow = 5, byrow = TRUE)
  simulate(initial_grid)
}

main()