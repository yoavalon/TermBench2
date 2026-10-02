r
library(stats)

rotate_point <- function(x, y, z, angle, axis) {
  if (axis == 'x') {
    cos_a <- cos(angle)
    sin_a <- sin(angle)
    y_new <- cos_a * y - sin_a * z
    z_new <- sin_a * y + cos_a * z
    return(c(x, y_new, z_new))
  } else if (axis == 'y') {
    cos_a <- cos(angle)
    sin_a <- sin(angle)
    x_new <- cos_a * x + sin_a * z
    z_new <- -sin_a * x + cos_a * z
    return(c(x_new, y, z_new))
  } else if (axis == 'z') {
    cos_a <- cos(angle)
    sin_a <- sin(angle)
    x_new <- cos_a * x - sin_a * y
    y_new <- sin_a * x + cos_a * y
    return(c(x_new, y_new, z))
  }
  return(c(x, y, z))
}

scale_point <- function(x, y, z, scale_x, scale_y, scale_z) {
  return(c(x * scale_x, y * scale_y, z * scale_z))
}

transform_sequence <- function(point, rotations, scales) {
  x <- point[1]
  y <- point[2]
  z <- point[3]
  for (rotation in rotations) {
    result <- rotate_point(x, y, z, rotation[1], rotation[2])
    x <- result[1]
    y <- result[2]
    z <- result[3]
  }
  for (scale in scales) {
    result <- scale_point(x, y, z, scale[1], scale[2], scale[3])
    x <- result[1]
    y <- result[2]
    z <- result[3]
  }
  return(c(x, y, z))
}

main <- function() {
  initial_point <- c(1, 1, 1)
  rotations <- list(c(pi / 4, 'x'), c(pi / 4, 'y'))
  scales <- list(c(2, 2, 2))
  while (TRUE) {
    new_point <- transform_sequence(initial_point, rotations, scales)
    print(new_point)
  }
}

main()