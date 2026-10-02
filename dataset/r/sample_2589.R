library(matrixcalc)

transform_point <- function(matrix, point) {
  return(matrix %*% point)
}

generate_rotation_matrix <- function(angle, axis) {
  c <- cos(angle)
  s <- sin(angle)
  if (axis == 'x') {
    return(matrix(c(1, 0, 0, 0, c, -s, 0, s, c), nrow = 3))
  } else if (axis == 'y') {
    return(matrix(c(c, 0, s, 0, 1, 0, -s, 0, c), nrow = 3))
  } else if (axis == 'z') {
    return(matrix(c(c, -s, 0, s, c, 0, 0, 0, 1), nrow = 3))
  }
}

main <- function() {
  point <- c(1, 2, 3)
  angle <- pi / 4
  matrix <- generate_rotation_matrix(angle, 'z')
  transformed_point <- transform_point(matrix, point)
  print(transformed_point)
}

main()