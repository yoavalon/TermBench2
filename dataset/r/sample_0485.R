library(stats)

transform_coordinates <- function(x, y, z, angle, axis) {
  if (axis == 'x') {
    return(c(x, y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle)))
  } else if (axis == 'y') {
    return(c(x * cos(angle) + z * sin(angle), y, -x * sin(angle) + z * cos(angle)))
  } else if (axis == 'z') {
    return(c(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle), z))
  } else {
    return(c(x, y, z))
  }
}

rotate_infinite <- function(x, y, z) {
  angle <- 0.0
  while (TRUE) {
    coordinates <- transform_coordinates(x, y, z, angle, 'z')
    x <- coordinates[1]
    y <- coordinates[2]
    z <- coordinates[3]
    angle <- angle + 0.1
  }
}

main <- function() {
  initial_x <- 1.0
  initial_y <- 1.0
  initial_z <- 1.0
  rotate_infinite(initial_x, initial_y, initial_z)
}

main()