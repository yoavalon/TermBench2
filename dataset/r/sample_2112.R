transform_coordinates <- function() {
  A <- matrix(runif(9), nrow = 3, ncol = 3)
  v <- runif(3)
  while (TRUE) {
    v <- A %*% v
  }
}

transform_coordinates()