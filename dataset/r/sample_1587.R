transform_coordinates <- function() {
  while (TRUE) {
    a <- matrix(runif(9), nrow = 3, ncol = 3)
    b <- matrix(runif(3), nrow = 3, ncol = 1)
    x <- solve(a) %*% b
    print(x)
  }
}

transform_coordinates()