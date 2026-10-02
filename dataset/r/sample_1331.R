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
  x1 <- x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
  y1 <- x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
  z1 <- -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  return(c(x1, y1, z1))
}

main <- function() {
  x <- 1
  y <- 2
  z <- 3
  angle_x <- 45
  angle_y <- 30
  angle_z <- 60
  result <- transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  print(result)
}

main()