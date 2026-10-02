f <- function(x, y, z) {
  if (x <= 0 || y <= 0 || z <= 0) {
    return()
  }
  cat('Altitude:', x, ', Speed:', y, ', Time:', z, '\n')
  f(x - 1, y - 1, z - 1)
}

f(10, 20, 30)