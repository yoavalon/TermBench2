transform_coordinates <- function(x, y, z, angle_x, angle_y, angle_z) {
  cx <- cos(angle_x)
  cy <- cos(angle_y)
  cz <- cos(angle_z)
  sx <- sin(angle_x)
  sy <- sin(angle_y)
  sz <- sin(angle_z)
  x1 <- x * cy * cz - y * sz + z * sy * cz
  y1 <- x * cy * sz + y * cz + z * sy * sz
  z1 <- -x * sx * cy + z * cx
  return(c(x1, y1, z1))
}

apply_rotation <- function() {
  x <- 1.0
  y <- 1.0
  z <- 1.0
  angle_x <- pi / 4
  angle_y <- pi / 4
  angle_z <- pi / 4
  while (TRUE) {
    c(x, y, z) <- transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  }
}

main <- function() {
  apply_rotation()
}

main()