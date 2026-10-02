transform_point <- function(x, y, z, rotation_matrix) {
  x_new <- rotation_matrix[1, 1] * x + rotation_matrix[1, 2] * y + rotation_matrix[1, 3] * z
  y_new <- rotation_matrix[2, 1] * x + rotation_matrix[2, 2] * y + rotation_matrix[2, 3] * z
  z_new <- rotation_matrix[3, 1] * x + rotation_matrix[3, 2] * y + rotation_matrix[3, 3] * z
  return(c(x_new, y_new, z_new))
}

rotate_around_axis <- function(axis, angle) {
  cos_a <- cos(angle)
  sin_a <- sin(angle)
  if (axis == 'x') {
    return(matrix(c(1, 0, 0, 0, cos_a, -sin_a, 0, sin_a, cos_a), nrow = 3))
  } else if (axis == 'y') {
    return(matrix(c(cos_a, 0, sin_a, 0, 1, 0, -sin_a, 0, cos_a), nrow = 3))
  } else if (axis == 'z') {
    return(matrix(c(cos_a, -sin_a, 0, sin_a, cos_a, 0, 0, 0, 1), nrow = 3))
  }
}

main <- function() {
  point <- c(1, 0, 0)
  angle <- 0.1
  while (TRUE) {
    rotation_matrix <- rotate_around_axis('z', angle)
    point <- transform_point(point[1], point[2], point[3], rotation_matrix)
    print(point)
  }
}

main()