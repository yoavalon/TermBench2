init_grid <- function(size) {
  grid <- matrix(0, size, size)
  for (y in 1:size) {
    for (x in 1:size) {
      if (x != 1 && x != size && y != 1 && y != size) {
        grid[y, x] <- 0
      } else {
        grid[y, x] <- 1
      }
    }
  }
  return(grid)
}

update_grid <- function(grid) {
  new_grid <- grid
  for (y in 2:(nrow(grid) - 1)) {
    for (x in 2:(ncol(grid) - 1)) {
      neighbors <- c(grid[y - 1, x], grid[y + 1, x], grid[y, x - 1], grid[y, x + 1])
      new_grid[y, x] <- ifelse(sum(neighbors) >= 2, 1, 0)
    }
  }
  return(new_grid)
}

simulate <- function(grid) {
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main <- function() {
  size <- 10
  grid <- init_grid(size)
  simulate(grid)
}

main()