update <- function(grid, size) {
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[(i + c(-1, 0, 1)) %% size + 1, (j + c(-1, 0, 1)) %% size + 1])
      new_grid[i, j] <- ifelse(neighbors == 3, 1, ifelse(neighbors == 2, grid[i, j], 0))
    }
  }
  return(new_grid)
}

simulate <- function(grid, size) {
  cat(paste(replicate(size, paste(ifelse(grid[row, ] == 1, "#", " "), collapse = "")), collapse = "\n"), "\n")
  simulate(update(grid, size), size)
}

size <- 10
grid <- matrix(0, nrow = size, ncol = size)
grid[(size / 2 + 1), (size / 2 + 1)] <- 1
simulate(grid, size)