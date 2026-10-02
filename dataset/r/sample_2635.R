library(Matrix)

transform_matrix <- function(rotation, translation) {
  R <- as.matrix(rotation)
  T <- as.matrix(translation)
  return(rbind(cbind(R, T), c(0, 0, 0, 1)))
}

apply_transformation <- function(points, matrix) {
  homogeneous_points <- cbind(points, rep(1, nrow(points)))
  transformed_points <- homogeneous_points %*% t(matrix)
  return(transformed_points[, 1:3])
}

generate_sequence <- function(n, initial_point, angle, axis) {
  sequence <- list(initial_point)
  rotation_matrix <- diag(3)
  for (i in 1:n) {
    rotation_matrix <- rotate_around_axis(rotation_matrix, angle, axis)
    transformed_point <- apply_transformation(matrix(sequence[[length(sequence)]], nrow = 1), rotation_matrix)
    sequence <- c(sequence, list(transformed_point))
  }
  return(do.call(rbind, sequence))
}

rotate_around_axis <- function(matrix, angle, axis) {
  cos_angle <- cos(angle)
  sin_angle <- sin(angle)
  axis <- axis / norm(axis, type = "2")
  ux <- axis[1]
  uy <- axis[2]
  uz <- axis[3]
  rotation <- matrix(c(cos_angle + ux^2 * (1 - cos_angle), ux * uy * (1 - cos_angle) - uz * sin_angle, ux * uz * (1 - cos_angle) + uy * sin_angle, uy * ux * (1 - cos_angle) + uz * sin_angle, cos_angle + uy^2 * (1 - cos_angle), uy * uz * (1 - cos_angle) - ux * sin_angle, uz * ux * (1 - cos_angle) - uy * sin_angle, uz * uy * (1 - cos_angle) + ux * sin_angle, cos_angle + uz^2 * (1 - cos_angle)), nrow = 3, byrow = TRUE)
  return(rotation %*% matrix)
}

main <- function() {
  initial_point <- c(1, 0, 0)
  angle <- pi / 4
  axis <- c(0, 0, 1)
  n <- 10
  sequence <- generate_sequence(n, initial_point, angle, axis)
  print(sequence)
}

main()