init_grid <- function(size) {
  matrix(sample(c(0, 1), size * size, replace = TRUE), nrow = size, ncol = size)
}

update_grid <- function(grid) {
  new_grid <- grid
  for (i in 2:nrow(grid) - 1) {
    for (j in 2:ncol(grid) - 1) {
      neighbors <- sum(grid[i - 1:i + 1, j - 1:j + 1]) - grid[i, j]
      if (grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
        new_grid[i, j] <- 0
      } else if (grid[i, j] == 0 && neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 10
  grid <- init_grid(size)
  while (TRUE) {
    grid <- update_grid(grid)
    print(grid)
    print(rep('-', 40))
  }
}

main()