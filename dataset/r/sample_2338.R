library(matrixStats)

matrix_multiply <- function(A, B) {
  rows_A <- nrow(A)
  cols_A <- ncol(A)
  cols_B <- ncol(B)
  result <- matrix(0.0, nrow = rows_A, ncol = cols_B)
  for (i in 1:rows_A) {
    for (j in 1:cols_B) {
      for (k in 1:cols_A) {
        result[i, j] <- result[i, j] + A[i, k] * B[k, j]
      }
    }
  }
  return(result)
}

rotation_matrix <- function(angle) {
  cos_theta <- cos(angle)
  sin_theta <- sin(angle)
  return(matrix(c(cos_theta, -sin_theta, 0.0, sin_theta, cos_theta, 0.0, 0.0, 0.0, 1.0), nrow = 3, byrow = TRUE))
}

transform_point <- function(point, matrix) {
  x <- point[1]
  y <- point[2]
  z <- point[3]
  transformed <- matrix_multiply(matrix, matrix(c(x, y, z), nrow = 3, byrow = FALSE))
  return(c(transformed[1], transformed[2], transformed[3]))
}

continuous_rotation <- function(point, angle_step) {
  angle <- 0.0
  while (TRUE) {
    rotation <- rotation_matrix(angle)
    new_point <- transform_point(point, rotation)
    print(new_point)
    angle <- angle + angle_step
  }
}

main <- function() {
  point <- c(1.0, 0.0, 0.0)
  angle_step <- 0.1
  continuous_rotation(point, angle_step)
}

main()