r
transform_coordinates <- function(x, y, z, angle_x, angle_y, angle_z) {
  angle_x <- angle_x * pi / 180
  angle_y <- angle_y * pi / 180
  angle_z <- angle_z * pi / 180
  x1 <- x * cos(angle_y) * cos(angle_z) - y * sin(angle_z) + z * sin(angle_y) * cos(angle_z)
  y1 <- x * cos(angle_y) * sin(angle_z) + y * cos(angle_z) + z * sin(angle_y) * sin(angle_z)
  z1 <- -x * sin(angle_y) + z * cos(angle_y)
  return(c(x1, y1, z1))
}

continuous_transformation <- function() {
  x <- 1
  y <- 0
  z <- 0
  angle_x <- 1
  angle_y <- 0
  angle_z <- 0
  while (TRUE) {
    coords <- transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    x <- coords[1]
    y <- coords[2]
    z <- coords[3]
    angle_x <- angle_x + 1
    angle_y <- angle_y + 1
    angle_z <- angle_z + 1
  }
}

continuous_transformation()