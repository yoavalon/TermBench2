r
rotate_point <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_a <- cos(rad)
  sin_a <- sin(rad)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  z_new <- z
  return(c(x_new, y_new, z_new))
}

transform_sequence <- function(points, angle) {
  result <- list()
  for (p in points) {
    x <- p[1]
    y <- p[2]
    z <- p[3]
    new_point <- rotate_point(x, y, z, angle)
    result <- c(result, list(new_point))
  }
  return(result)
}

main <- function() {
  points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  angle <- 10
  while (TRUE) {
    points <- transform_sequence(points, angle)
    angle <- angle + 5
  }
}

main()