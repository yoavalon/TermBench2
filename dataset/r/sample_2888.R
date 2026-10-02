library(stats)

transform_point <- function(x, y, z, angle_x, angle_y, angle_z) {
  cx <- cos(angle_x)
  cy <- cos(angle_y)
  cz <- cos(angle_z)
  sx <- sin(angle_x)
  sy <- sin(angle_y)
  sz <- sin(angle_z)
  x_new <- cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z)
  y_new <- sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z)
  z_new <- cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z))
  return(c(x_new, y_new, z_new))
}

continuous_transform <- function() {
  x <- 0
  y <- 0
  z <- 0
  angle_x <- 0.1
  angle_y <- 0.2
  angle_z <- 0.3
  while (TRUE) {
    c(x, y, z) <- transform_point(x, y, z, angle_x, angle_y, angle_z)
    angle_x <- angle_x + 0.01
    angle_y <- angle_y + 0.02
    angle_z <- angle_z + 0.03
  }
}

continuous_transform()