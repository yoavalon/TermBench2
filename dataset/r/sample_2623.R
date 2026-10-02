Matrix <- R6::R6Class("Matrix",
  public = list(
    data = NULL,
    rows = NULL,
    cols = NULL,
    initialize = function(data) {
      self$data <- data
      self$rows <- nrow(data)
      self$cols <- ifelse(self$rows > 0, ncol(data), 0)
    },
    multiply = function(other) {
      result <- matrix(0, nrow = self$rows, ncol = other$cols)
      for (i in 1:self$rows) {
        for (j in 1:other$cols) {
          for (k in 1:other$rows) {
            result[i, j] <- result[i, j] + self$data[i, k] * other$data[k, j]
          }
        }
      }
      return(Matrix$new(result))
    },
    print = function() {
      for (row in 1:self$rows) {
        cat(paste(self$data[row, ], collapse = " "), "\n")
      }
    }
  )
)

rotation_matrix <- function(axis, theta) {
  if (axis == "x") {
    return(Matrix$new(matrix(c(1, 0, 0, 0, cos(theta), -sin(theta), 0, sin(theta), cos(theta)), nrow = 3)))
  } else if (axis == "y") {
    return(Matrix$new(matrix(c(cos(theta), 0, sin(theta), 0, 1, 0, -sin(theta), 0, cos(theta)), nrow = 3)))
  } else if (axis == "z") {
    return(Matrix$new(matrix(c(cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1), nrow = 3)))
  }
}

transform_point <- function(matrix, point) {
  point_matrix <- Matrix$new(matrix(c(point[1], point[2], point[3]), nrow = 3))
  transformed <- matrix$multiply(point_matrix)
  return(c(transformed$data[1, 1], transformed$data[2, 1], transformed$data[3, 1]))
}

main <- function() {
  point <- c(1, 2, 3)
  theta <- 0.785398
  matrix_x <- rotation_matrix("x", theta)
  matrix_y <- rotation_matrix("y", theta)
  matrix_z <- rotation_matrix("z", theta)
  transformed_x <- transform_point(matrix_x, point)
  transformed_y <- transform_point(matrix_y, point)
  transformed_z <- transform_point(matrix_z, point)
  cat("Transformed by X-axis: ", paste(transformed_x, collapse = " "), "\n")
  cat("Transformed by Y-axis: ", paste(transformed_y, collapse = " "), "\n")
  cat("Transformed by Z-axis: ", paste(transformed_z, collapse = " "), "\n")
}

main()