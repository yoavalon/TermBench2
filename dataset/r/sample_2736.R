main <- function() {
  library(abind)
  
  update <- function(grid) {
    return ((grid + shift(grid, 1, dim = 1) + shift(grid, -1, dim = 1) + shift(grid, 1, dim = 2) + shift(grid, -1, dim = 2)) %% 2)
  }
  
  grid <- matrix(0, nrow = 100, ncol = 100, byrow = TRUE)
  grid[50, 50] <- 1
  
  while (TRUE) {
    grid <- update(grid)
  }
}

main()