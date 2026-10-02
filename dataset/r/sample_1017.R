update_grid <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (x in 1:size) {
    for (y in 1:size) {
      neighbors <- 0
      for (dx in -1:1) {
        for (dy in -1:1) {
          if (!(dx == 0 & dy == 0)) {
            neighbors <- neighbors + grid[(x + dx - 1) %% size + 1, (y + dy - 1) %% size + 1]
          }
        }
      }
      new_grid[x, y] <- ifelse(2 <= neighbors & neighbors <= 3, 1, 0)
    }
  }
  return(new_grid)
}

simulate <- function(grid) {
  if (length(grid) == 0) {
    grid <- matrix(sample(0:1, 100, replace = TRUE), nrow = 10)
  }
  cat(paste0(apply(grid, 1, paste, collapse = ""), collapse = "\n"), "\n")
  simulate(update_grid(grid))
}

simulate(matrix(numeric(), nrow = 0))