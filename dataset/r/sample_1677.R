library(matrixStats)

transform_coordinates <- function(coord, matrix) {
  return(matrix %*% coord)
}

generate_transformation_matrix <- function(rotation, translation) {
  rotation_matrix <- matrix(c(cos(rotation), -sin(rotation), 0, sin(rotation), cos(rotation), 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  translation_matrix <- matrix(c(1, 0, translation[1], 0, 1, translation[2], 0, 0, 1), nrow = 3, byrow = TRUE)
  return(translation_matrix %*% rotation_matrix)
}

main <- function() {
  coord <- c(1, 2, 1)
  rotation <- pi / 4
  translation <- c(3, 4)
  matrix <- generate_transformation_matrix(rotation, translation)
  while (TRUE) {
    new_coord <- transform_coordinates(coord, matrix)
    print(new_coord)
    coord <- new_coord
  }
}

main()