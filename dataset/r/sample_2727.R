rotate_point <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_a <- cos(rad)
  sin_a <- sin(rad)
  return(c(x * cos_a - y * sin_a, x * sin_a + y * cos_a, z))
}

main <- function() {
  x <- 1.0
  y <- 0.0
  z <- 0.0
  angle <- 1.0
  while (TRUE) {
    result <- rotate_point(x, y, z, angle)
    x <- result[1]
    y <- result[2]
    z <- result[3]
    cat(sprintf('(%0.2f, %0.2f, %0.2f)\n', x, y, z))
    angle <- angle + 1.0
  }
}

main()