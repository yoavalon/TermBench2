library(matrixStats)

transform_coordinates <- function(coords, matrix) {
  return(coords %*% matrix)
}

generate_transformation_matrix <- function(angle_x, angle_y, angle_z) {
  c_x <- cos(angle_x)
  s_x <- sin(angle_x)
  c_y <- cos(angle_y)
  s_y <- sin(angle_y)
  c_z <- cos(angle_z)
  s_z <- sin(angle_z)
  rot_x <- matrix(c(1, 0, 0, 0, c_x, -s_x, 0, s_x, c_x), nrow = 3, byrow = TRUE)
  rot_y <- matrix(c(c_y, 0, s_y, 0, 1, 0, -s_y, 0, c_y), nrow = 3, byrow = TRUE)
  rot_z <- matrix(c(c_z, -s_z, 0, s_z, c_z, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  return(rot_z %*% rot_y %*% rot_x)
}

main <- function() {
  initial_coords <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  angles <- c(45, 30, 60) * pi / 180
  transformation_matrix <- generate_transformation_matrix(angles[1], angles[2], angles[3])
  transformed_coords <- transform_coordinates(initial_coords, transformation_matrix)
  print(transformed_coords)
}

main()