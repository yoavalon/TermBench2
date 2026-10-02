library(matrixStats)

transform_coordinates <- function(matrix, points) {
  return(matrix %*% t(points))
}

rotate_3d <- function(x, y, z, angle) {
  rad <- angle * pi / 180
  c <- cos(rad)
  s <- sin(rad)
  rot_matrix <- matrix(c(c, -s, 0, s, c, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  points <- matrix(c(x, y, z), nrow = 3)
  return(transform_coordinates(rot_matrix, points))
}

main <- function() {
  x <- 1
  y <- 2
  z <- 3
  angle <- 45
  result <- rotate_3d(x, y, z, angle)
  print(result)
}

main()