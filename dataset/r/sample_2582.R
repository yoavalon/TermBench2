initialize_grid <- function(size) {
  grid <- matrix(sample(0:1, size^2, replace = TRUE), nrow = size, ncol = size)
  return(grid)
}

update_grid <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[(i + c(-1, 0, 1)) %% size + 1, (j + c(-1, 0, 1)) %% size + 1])
      new_grid[i, j] <- ifelse(neighbors == 3 | (grid[i, j] == 1 & neighbors == 2), 1, 0)
    }
  }
  return(new_grid)
}

simulate <- function(steps, size) {
  grid <- initialize_grid(size)
  for (step in 1:steps) {
    grid <- update_grid(grid)
  }
  return(grid)
}

main <- function() {
  steps <- 10
  size <- 5
  result <- simulate(steps, size)
  for (row in result) {
    cat(paste(row, collapse = " "), "\n")
  }
}

main()