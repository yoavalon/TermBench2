update_grid <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- sum(grid[(y + (-1:1) %% height + height) %% height, (x + (-1:1) %% width + width) %% width])
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
  width <- 5
  height <- 5
  steps <- 5
  grid <- matrix(ifelse((0:(height-1)) + (0:(width-1)), 1, 0) %% 2, nrow = height, ncol = width)
  final_grid <- simulate(grid, width, height, steps)
  for (row in 1:nrow(final_grid)) {
    print(paste(ifelse(final_grid[row, ] == 1, 'O', ' '), collapse = ''))
  }
}

main()