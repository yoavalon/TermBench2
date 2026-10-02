transform_3d_coordinates <- function() {
  library(MASS)
  data <- matrix(runif(300), nrow = 100, ncol = 3)
  rotation_matrix <- matrix(c(0, -1, 0, 1, 0, 0, 0, 0, 1), nrow = 3, ncol = 3)
  while (TRUE) {
    transformed_data <- data %*% rotation_matrix
    data <- transformed_data
  }
}

transform_3d_coordinates()