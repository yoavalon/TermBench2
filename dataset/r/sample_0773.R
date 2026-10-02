update_grid <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- sum(grid[max(1, y - 1):min(height, y + 1), max(1, x - 1):min(width, x + 1)]) - grid[y, x]
      new_grid[y, x] <- ifelse(neighbors == 3 | (neighbors == 2 & grid[y, x] == 1), 1, 0)
    }
  }
  return(new_grid)
}

simulate <- function(grid, width, height, steps) {
  for (i in 1:steps) {
    grid <- update_grid(grid, width, height)
  }
  return(grid)
}

main <- function() {
  width <- 10
  height <- 10
  steps <- 5
  initial_grid <- matrix(0, nrow = height, ncol = width)
  initial_grid[5, 5] <- 1
  result <- simulate(initial_grid, width, height, steps)
  for (i in 1:nrow(result)) {
    cat(paste(ifelse(result[i, ] == 1, "O", " "), collapse = ""), "\n")
  }
}

main()