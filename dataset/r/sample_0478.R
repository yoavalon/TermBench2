library(stats)

transform_coordinates <- function(x, y, z, angle) {
  rad <- radians(angle)
  cos_val <- cos(rad)
  sin_val <- sin(rad)
  x_new <- x * cos_val - y * sin_val
  y_new <- x * sin_val + y * cos_val
  z_new <- z
  return(c(x_new, y_new, z_new))
}

rotate_around_axis <- function(points, axis, angle) {
  if (axis == 'x') {
    return(apply(points, 1, function(point) {
      c(point[1], point[2] * cos(angle) - point[3] * sin(angle), point[2] * sin(angle) + point[3] * cos(angle))
    }))
  } else if (axis == 'y') {
    return(apply(points, 1, function(point) {
      c(point[1] * cos(angle) + point[3] * sin(angle), point[2], -point[1] * sin(angle) + point[3] * cos(angle))
    }))
  } else if (axis == 'z') {
    return(apply(points, 1, function(point) {
      c(point[1] * cos(angle) - point[2] * sin(angle), point[1] * sin(angle) + point[2] * cos(angle), point[3])
    }))
  }
  return(points)
}

main <- function() {
  points <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  angle <- pi / 4
  transformed_points <- rotate_around_axis(points, 'z', angle)
  while (TRUE) {
    for (i in 1:nrow(transformed_points)) {
      print(transformed_points[i, ])
    }
    transformed_points <- rotate_around_axis(transformed_points, 'x', angle)
  }
}

main()