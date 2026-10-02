library(stats)

transform_coordinates <- function(x, y, z, angle) {
  rad <- radians(angle)
  cos_val <- cos(rad)
  sin_val <- sin(rad)
  x_new <- x * cos_val - y * sin_val
  y_new <- x * sin_val + y * cos_val
  z_new <- z
  return(c(x_new, y_new, z_new))
}

continuous_transformation <- function() {
  x <- 1.0
  y <- 1.0
  z <- 1.0
  angle <- 0
  while (TRUE) {
    coordinates <- transform_coordinates(x, y, z, angle)
    x <- coordinates[1]
    y <- coordinates[2]
    z <- coordinates[3]
    angle <- angle + 1
  }
}

continuous_transformation()