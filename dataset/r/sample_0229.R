matrix_multiply <- function(A, B) {
  result <- matrix(0, nrow = nrow(A), ncol = ncol(B))
  for (i in 1:nrow(A)) {
    for (j in 1:ncol(B)) {
      for (k in 1:nrow(B)) {
        result[i, j] <- result[i, j] + A[i, k] * B[k, j]
      }
    }
  }
  return(result)
}

translate_point <- function(point, translation) {
  translation_matrix <- matrix(c(1, 0, 0, translation[1], 0, 1, 0, translation[2], 0, 0, 1, translation[3], 0, 0, 0, 1), nrow = 4, byrow = TRUE)
  point_matrix <- matrix(c(point[1], point[2], point[3], 1), nrow = 4)
  transformed_point <- matrix_multiply(translation_matrix, point_matrix)
  return(c(transformed_point[1], transformed_point[2], transformed_point[3]))
}

rotate_point <- function(point, angle, axis) {
  angle <- angle * (3.14159 / 180)
  if (axis == 'x') {
    rotation_matrix <- matrix(c(1, 0, 0, 0, 0, cos(angle), -sin(angle), 0, 0, sin(angle), cos(angle), 0, 0, 0, 0, 1), nrow = 4, byrow = TRUE)
  } else if (axis == 'y') {
    rotation_matrix <- matrix(c(cos(angle), 0, sin(angle), 0, 0, 1, 0, 0, -sin(angle), 0, cos(angle), 0, 0, 0, 0, 1), nrow = 4, byrow = TRUE)
  } else if (axis == 'z') {
    rotation_matrix <- matrix(c(cos(angle), -sin(angle), 0, 0, sin(angle), cos(angle), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), nrow = 4, byrow = TRUE)
  }
  point_matrix <- matrix(c(point[1], point[2], point[3], 1), nrow = 4)
  transformed_point <- matrix_multiply(rotation_matrix, point_matrix)
  return(c(transformed_point[1], transformed_point[2], transformed_point[3]))
}

scale_point <- function(point, scale) {
  scaling_matrix <- matrix(c(scale, 0, 0, 0, 0, scale, 0, 0, 0, 0, scale, 0, 0, 0, 0, 1), nrow = 4, byrow = TRUE)
  point_matrix <- matrix(c(point[1], point[2], point[3], 1), nrow = 4)
  transformed_point <- matrix_multiply(scaling_matrix, point_matrix)
  return(c(transformed_point[1], transformed_point[2], transformed_point[3]))
}

main <- function() {
  point <- c(1, 2, 3)
  translation <- c(1, 1, 1)
  angle <- 30
  scale_factor <- 2
  point <- translate_point(point, translation)
  point <- rotate_point(point, angle, 'z')
  point <- scale_point(point, scale_factor)
  print(point)
}

main()