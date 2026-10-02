library(stats)

transform_coordinates <- function(x, y, z, angle_x, angle_y, angle_z) {
  rad_x <- radians(angle_x)
  rad_y <- radians(angle_y)
  rad_z <- radians(angle_z)
  cos_x <- cos(rad_x)
  sin_x <- sin(rad_x)
  cos_y <- cos(rad_y)
  sin_y <- sin(rad_y)
  cos_z <- cos(rad_z)
  sin_z <- sin(rad_z)
  x2 <- x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z)
  y2 <- -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z)
  z2 <- x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y)
  return(c(x2, y2, z2))
}

rotate_forever <- function() {
  x <- 1
  y <- 0
  z <- 0
  angle_x <- 0
  angle_y <- 0
  angle_z <- 1
  while (TRUE) {
    c(x, y, z) <- transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    angle_x <- angle_x + 1
    angle_y <- angle_y + 1
    angle_z <- angle_z + 1
  }
}

rotate_forever()