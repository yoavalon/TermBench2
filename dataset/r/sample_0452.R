transform_coordinates <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_rad <- cos(rad)
  sin_rad <- sin(rad)
  x_new <- x * cos_rad - y * sin_rad
  y_new <- x * sin_rad + y * cos_rad
  z_new <- z
  return(c(x_new, y_new, z_new))
}

apply_transformation <- function() {
  x <- 1.0
  y <- 2.0
  z <- 3.0
  angle <- 0.0
  while (TRUE) {
    c(x, y, z) <- transform_coordinates(x, y, z, angle)
    angle <- angle + 1
  }
}

apply_transformation()