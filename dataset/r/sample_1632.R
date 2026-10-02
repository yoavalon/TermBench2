library(abind)

transform_coordinates <- function(x, y, z, angle_x, angle_y, angle_z) {
  radians_x <- angle_x * pi / 180
  radians_y <- angle_y * pi / 180
  radians_z <- angle_z * pi / 180
  rotation_x <- matrix(c(1, 0, 0, 0, cos(radians_x), -sin(radians_x), 0, sin(radians_x), cos(radians_x)), nrow = 3, byrow = TRUE)
  rotation_y <- matrix(c(cos(radians_y), 0, sin(radians_y), 0, 1, 0, -sin(radians_y), 0, cos(radians_y)), nrow = 3, byrow = TRUE)
  rotation_z <- matrix(c(cos(radians_z), -sin(radians_z), 0, sin(radians_z), cos(radians_z), 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  point <- c(x, y, z)
  transformed_point <- aperm(rotation_x %*% rotation_y %*% rotation_z %*% point, c(2, 1))
  return(transformed_point)
}

continuously_transform <- function() {
  x <- 1
  y <- 0
  z <- 0
  angle_x <- 10
  angle_y <- 20
  angle_z <- 30
  while (TRUE) {
    result <- transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    x <- result[1]
    y <- result[2]
    z <- result[3]
    angle_x <- (angle_x + 5) %% 360
    angle_y <- (angle_y + 10) %% 360
    angle_z <- (angle_z + 15) %% 360
  }
}

main <- function() {
  continuously_transform()
}

main()