library(Matrix)

transform_coordinates <- function(coords, matrix) {
  return(matrix %*% coords)
}

generate_transformation_matrix <- function(angle_x, angle_y, angle_z) {
  Rx <- matrix(c(1, 0, 0, 0, cos(angle_x), -sin(angle_x), 0, sin(angle_x), cos(angle_x)), nrow = 3, byrow = TRUE)
  Ry <- matrix(c(cos(angle_y), 0, sin(angle_y), 0, 1, 0, -sin(angle_y), 0, cos(angle_y)), nrow = 3, byrow = TRUE)
  Rz <- matrix(c(cos(angle_z), -sin(angle_z), 0, sin(angle_z), cos(angle_z), 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  return(Rx %*% Ry %*% Rz)
}

main <- function() {
  coords <- c(1, 2, 3)
  angles <- c(pi / 4, pi / 3, pi / 6)
  matrix <- generate_transformation_matrix(angles[1], angles[2], angles[3])
  new_coords <- transform_coordinates(coords, matrix)
  print(new_coords)
}

main()