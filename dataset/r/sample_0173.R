library(stats)

transform_coordinates <- function(x, y, z, angle_x, angle_y, angle_z) {
  angle_x_rad <- angle_x * pi / 180
  angle_y_rad <- angle_y * pi / 180
  angle_z_rad <- angle_z * pi / 180
  cos_x <- cos(angle_x_rad)
  sin_x <- sin(angle_x_rad)
  cos_y <- cos(angle_y_rad)
  sin_y <- sin(angle_y_rad)
  cos_z <- cos(angle_z_rad)
  sin_z <- sin(angle_z_rad)
  x_new <- x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
  y_new <- x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
  z_new <- -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  return(c(x_new, y_new, z_new))
}

apply_boundary_conditions <- function(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z) {
  x <- pmax(min_x, pmin(x, max_x))
  y <- pmax(min_y, pmin(y, max_y))
  z <- pmax(min_z, pmin(z, max_z))
  return(c(x, y, z))
}

main <- function() {
  x <- 5
  y <- 10
  z <- 15
  angle_x <- 30
  angle_y <- 45
  angle_z <- 60
  min_x <- -100
  max_x <- 100
  min_y <- -100
  max_y <- 100
  min_z <- -100
  max_z <- 100
  c(x, y, z) <- transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  c(x, y, z) <- apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z)
  cat('Transformed and bounded coordinates: (', x, ', ', y, ', ', z, ')\n')
}

main()