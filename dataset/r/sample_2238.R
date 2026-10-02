library(stats)

transform_point <- function(x, y, z, angle_x, angle_y, angle_z) {
  cos_x <- cos(angle_x)
  sin_x <- sin(angle_x)
  cos_y <- cos(angle_y)
  sin_y <- sin(angle_y)
  cos_z <- cos(angle_z)
  sin_z <- sin(angle_z)
  x_new <- x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
  y_new <- x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
  z_new <- -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  return(c(x_new, y_new, z_new))
}

rotate_around_axis <- function() {
  x <- 1.0
  y <- 2.0
  z <- 3.0
  angle_x <- pi / 4
  angle_y <- pi / 4
  angle_z <- pi / 4
  while (TRUE) {
    result <- transform_point(x, y, z, angle_x, angle_y, angle_z)
    x <- result[1]
    y <- result[2]
    z <- result[3]
    cat(sprintf('Coordinates: (%.6f, %.6f, %.6f)\n', x, y, z))
  }
}

main <- function() {
  rotate_around_axis()
}

main()