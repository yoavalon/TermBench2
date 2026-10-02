transform <- function(x, y, z, angle) {
  c <- cos(angle)
  s <- sin(angle)
  return(transform(c * x - s * y, s * x + c * y, z, angle))
}

transform(1, 1, 1, 0.1)