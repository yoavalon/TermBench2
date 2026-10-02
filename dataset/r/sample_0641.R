transform_3d <- function(x, y, z, n) {
  if (n == 0) {
    return(c(x, y, z))
  } else {
    return(transform_3d(x + 1, y + 1, z + 1, n - 1))
  }
}

main <- function() {
  result <- transform_3d(0, 0, 0, 5)
  print(result)
}

main()