library(pracma)

generate_grid <- function(size) {
  matrix(sample(c(0, 1), size * size, replace = TRUE), nrow = size, ncol = size)
}

update_grid <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[modulo(i + c(-1, 0, 1), size) + 1, modulo(j + c(-1, 0, 1), size) + 1], na.rm = TRUE) - grid[i, j]
      if ((grid[i, j] == 1 && neighbors %in% c(2, 3)) || (grid[i, j] == 0 && neighbors == 3)) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  size <- 10
  grid <- generate_grid(size)
  while (TRUE) {
    grid <- update_grid(grid)
  }
}

main()