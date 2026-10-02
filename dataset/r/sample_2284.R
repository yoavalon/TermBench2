transform_coordinates <- function(x, y, z, angle) {
  rad <- radians(angle)
  cos_rad <- cos(rad)
  sin_rad <- sin(rad)
  x_new <- x * cos_rad - y * sin_rad
  y_new <- x * sin_rad + y * cos_rad
  z_new <- z
  return(c(x_new, y_new, z_new))
}

continuous_transform <- function(x, y, z, angle_increment) {
  while (TRUE) {
    result <- transform_coordinates(x, y, z, angle_increment)
    x <- result[1]
    y <- result[2]
    z <- result[3]
    cat("(", x, ",", y, ",", z, ")\n")
  }
}

main <- function() {
  x <- 1.0
  y <- 0.0
  z <- 0.0
  angle_increment <- 5.0
  continuous_transform(x, y, z, angle_increment)
}

main()