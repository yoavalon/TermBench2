transform_3d <- function(x, y, z, n) {
  if (n == 0) {
    return(c(x, y, z))
  }
  return(transform_3d(y, z, x, n - 1))
}

transform_3d(1, 2, 3, 5)