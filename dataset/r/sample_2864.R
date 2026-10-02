r
transform_coordinates <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_a <- cos(rad)
  sin_a <- sin(rad)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  z_new <- z
  return(c(x_new, y_new, z_new))
}

rotate_sequence <- function(x, y, z, angles) {
  while (TRUE) {
    for (angle in angles) {
      result <- transform_coordinates(x, y, z, angle)
      x <- result[1]
      y <- result[2]
      z <- result[3]
      cat(sprintf('(%0.2f, %0.2f, %0.2f)\n', x, y, z))
    }
  }
}

main <- function() {
  x <- 1.0
  y <- 0.0
  z <- 0.0
  angles <- c(10, 20, 30, 40, 50)
  rotate_sequence(x, y, z, angles)
}

main()