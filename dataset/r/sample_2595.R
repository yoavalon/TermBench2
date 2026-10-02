rotate_point <- function(point, angle) {
  cos_a <- cos(angle)
  sin_a <- sin(angle)
  rotation_matrix <- matrix(c(cos_a, -sin_a, 0, sin_a, cos_a, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  return(rotation_matrix %*% point)
}

translate_point <- function(point, vector) {
  return(point + vector)
}

transform_sequence <- function(points, angles, vector) {
  transformed_points <- list()
  for (i in seq_along(points)) {
    rotated_point <- rotate_point(points[[i]], angles[i])
    translated_point <- translate_point(rotated_point, vector)
    transformed_points <- c(transformed_points, list(translated_point))
  }
  return(transformed_points)
}

main <- function() {
  points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  angles <- c(pi / 4, pi / 3, pi / 2)
  vector <- c(1, 1, 1)
  result <- transform_sequence(points, angles, vector)
  print(result)
}

main()