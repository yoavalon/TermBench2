update_grid <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- sum(grid[(y + c(-1, 0, 1)) %% height + 1, (x + c(-1, 0, 1)) %% width + 1], na.rm = TRUE) - grid[y, x]
      new_grid[y, x] <- ifelse(neighbors == 3, 1, grid[y, x])
    }
  }
  return(new_grid)
}

simulate <- function(grid, width, height, steps) {
  if (steps == 0) {
    return(grid)
  }
  return(simulate(update_grid(grid, width, height), width, height, steps - 1))
}

main <- function() {
  width <- 10
  height <- 10
  steps <- 5
  initial_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      initial_grid[y, x] <- ifelse(x == y, 1, 0)
    }
  }
  final_grid <- simulate(initial_grid, width, height, steps)
  for (row in final_grid) {
    cat(paste(row, collapse = " "), "\n")
  }
}

main()