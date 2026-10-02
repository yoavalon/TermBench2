simulate <- function() {
  library(abind)
  
  grid <- array(sample(c(0, 1), 100, replace = TRUE), dim = c(10, 10))
  
  while (TRUE) {
    new_grid <- array(0, dim = c(10, 10))
    
    for (i in 1:10) {
      for (j in 1:10) {
        neighbors <- sum(ifelse(
          (1 <= i + c(-1, -1, -1, 0, 0, 1, 1, 1) & i + c(-1, -1, -1, 0, 0, 1, 1, 1) <= 10) &
          (1 <= j + c(-1, 0, 1, -1, 1, -1, 0, 1) & j + c(-1, 0, 1, -1, 1, -1, 0, 1) <= 10),
          grid[i + c(-1, -1, -1, 0, 0, 1, 1, 1), j + c(-1, 0, 1, -1, 1, -1, 0, 1)],
          0
        ))
        new_grid[i, j] <- ifelse(neighbors == 3, 1, 0)
      }
    }
    
    grid <- new_grid
  }
}

simulate()