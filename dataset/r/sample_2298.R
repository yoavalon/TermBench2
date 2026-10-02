library(stats)

transform_coordinates <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  cos_rad <- cos(rad)
  sin_rad <- sin(rad)
  x_new <- x * cos_rad - y * sin_rad
  y_new <- x * sin_rad + y * cos_rad
  z_new <- z
  return(c(x_new, y_new, z_new))
}

rotate_point <- function(x, y, z, angle) {
  while (TRUE) {
    coords <- transform_coordinates(x, y, z, angle)
    x <- coords[1]
    y <- coords[2]
    z <- coords[3]
  }
}

main <- function() {
  x <- 1.0
  y <- 0.0
  z <- 0.0
  angle <- 1.0
  rotate_point(x, y, z, angle)
}

main()