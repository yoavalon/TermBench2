transform_coordinates <- function(x, y, z) {
  angle <- pi / 4
  cos_a <- cos(angle)
  sin_a <- sin(angle)
  x_new <- x * cos_a - y * sin_a
  y_new <- x * sin_a + y * cos_a
  z_new <- z
  return(c(x_new, y_new, z_new))
}

apply_transformation <- function() {
  x <- 1.0
  y <- 1.0
  z <- 1.0
  while (TRUE) {
    result <- transform_coordinates(x, y, z)
    x <- result[1]
    y <- result[2]
    z <- result[3]
    cat(sprintf('(%0.2f, %0.2f, %0.2f)\n', x, y, z))
  }
}

apply_transformation()