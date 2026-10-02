library(Matrix)

Vector3D <- R6Class("Vector3D",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    add = function(other) {
      Vector3D$new(self$x + other$x, self$y + other$y, self$z + other$z)
    },
    subtract = function(other) {
      Vector3D$new(self$x - other$x, self$y - other$y, self$z - other$z)
    },
    scale = function(factor) {
      Vector3D$new(self$x * factor, self$y * factor, self$z * factor)
    },
    dot = function(other) {
      self$x * other$x + self$y * other$y + self$z * other$z
    },
    magnitude = function() {
      sqrt(self$x^2 + self$y^2 + self$z^2)
    },
    normalize = function() {
      mag <- self$magnitude()
      Vector3D$new(self$x / mag, self$y / mag, self$z / mag)
    }
  )
)

Matrix3D <- R6Class("Matrix3D",
  public = list(
    data = NULL,
    initialize = function(a, b, c, d, e, f, g, h, i) {
      self$data <- matrix(c(a, b, c, d, e, f, g, h, i), nrow = 3, byrow = TRUE)
    },
    multiply = function(other) {
      result <- self$data %*% other$data
      Matrix3D$new(result[1,1], result[1,2], result[1,3], result[2,1], result[2,2], result[2,3], result[3,1], result[3,2], result[3,3])
    },
    transform = function(vector) {
      x <- self$data[1,] %*% c(vector$x, vector$y, vector$z)
      y <- self$data[2,] %*% c(vector$x, vector$y, vector$z)
      z <- self$data[3,] %*% c(vector$x, vector$y, vector$z)
      Vector3D$new(x, y, z)
    }
  )
)

rotation_matrix <- function(axis, theta) {
  if (axis == 'x') {
    Matrix3D$new(1, 0, 0, 0, cos(theta), -sin(theta), 0, sin(theta), cos(theta))
  } else if (axis == 'y') {
    Matrix3D$new(cos(theta), 0, sin(theta), 0, 1, 0, -sin(theta), 0, cos(theta))
  } else if (axis == 'z') {
    Matrix3D$new(cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1)
  }
}

main <- function() {
  v1 <- Vector3D$new(1, 2, 3)
  v2 <- Vector3D$new(4, 5, 6)
  v3 <- v1$add(v2)
  v4 <- v2$subtract(v1)
  v5 <- v3$scale(2)
  dot_product <- v1$dot(v2)
  magnitude_v1 <- v1$magnitude()
  normalized_v1 <- v1$normalize()
  rot_x <- rotation_matrix('x', pi / 4)
  rot_y <- rotation_matrix('y', pi / 4)
  rot_z <- rotation_matrix('z', pi / 4)
  v6 <- rot_x$transform(v1)
  v7 <- rot_y$transform(v1)
  v8 <- rot_z$transform(v1)
  matrix_product <- rot_x$multiply(rot_y)
  print(c(v3$x, v3$y, v3$z))
  print(c(v4$x, v4$y, v4$z))
  print(c(v5$x, v5$y, v5$z))
  print(dot_product)
  print(magnitude_v1)
  print(c(normalized_v1$x, normalized_v1$y, normalized_v1$z))
  print(c(v6$x, v6$y, v6$z))
  print(c(v7$x, v7$y, v7$z))
  print(c(v8$x, v8$y, v8$z))
  print(matrix_product$data)
}

main()