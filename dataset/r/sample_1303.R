rotate_point <- function(x, y, z, angle_x, angle_y, angle_z) {
  rad_x <- radians(angle_x)
  rad_y <- radians(angle_y)
  rad_z <- radians(angle_z)
  cos_x <- cos(rad_x)
  sin_x <- sin(rad_x)
  cos_y <- cos(rad_y)
  sin_y <- sin(rad_y)
  cos_z <- cos(rad_z)
  sin_z <- sin(rad_z)
  x_new <- x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y)
  y_new <- x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y)
  z_new <- -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  return(c(x_new, y_new, z_new))
}

scale_point <- function(x, y, z, scale) {
  return(c(x * scale, y * scale, z * scale))
}

main <- function() {
  point <- c(1, 1, 1)
  angles <- c(45, 30, 60)
  scale <- 2
  transformed_point <- rotate_point(point[1], point[2], point[3], angles[1], angles[2], angles[3])
  transformed_point <- scale_point(transformed_point[1], transformed_point[2], transformed_point[3], scale)
  cat('Transformed Point:', transformed_point, '\n')
}

main()