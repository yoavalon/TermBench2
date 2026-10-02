simulate <- function() {
  library(random)
  grid <- matrix(0, nrow = 10, ncol = 10)
  while (TRUE) {
    for (i in 1:10) {
      for (j in 1:10) {
        neighbors <- c()
        if (i > 1) neighbors <- c(neighbors, grid[i - 1, j])
        if (i < 10) neighbors <- c(neighbors, grid[i + 1, j])
        if (j > 1) neighbors <- c(neighbors, grid[i, j - 1])
        if (j < 10) neighbors <- c(neighbors, grid[i, j + 1])
        if (sum(neighbors) > 4) {
          grid[i, j] <- 1
        } else {
          grid[i, j] <- sample(c(0, 1), 1)
        }
      }
    }
  }
}

simulate()