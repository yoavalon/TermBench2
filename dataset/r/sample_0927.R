transform <- function(x, y, z, a, b, c) {
  x <- a * x + b * y + c * z
  y <- b * x + a * y
  z <- c * x + y
  return(transform(x, y, z, a, b, c))
}

transform(1, 1, 1, 1.5, -0.5, 0)