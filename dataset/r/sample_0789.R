r
update_grid <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- sum(grid[(y + c(-1, -1, -1, 0, 0, 1, 1, 1)) %% height + 1, (x + c(-1, 0, 1, -1, 1, -1, 0, 1)) %% width + 1])
      new_grid[y, x] <- ifelse(neighbors == 3 || (grid[y, x] == 1 && neighbors == 2), 1, 0)
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
  initial_grid <- matrix(ifelse(replicate(width * height, 0:1) %% 2 == 0, 1, 0), nrow = height, ncol = width)
  steps <- 5
  final_grid <- simulate(initial_grid, width, height, steps)
  for (row in 1:nrow(final_grid)) {
    cat(paste(final_grid[row, ], collapse = " "), "\n")
  }
}

main()