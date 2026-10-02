Vector3D <- setRefClass("Vector3D",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    add = function(other) {
      Vector3D(x = self$x + other$x, y = self$y + other$y, z = self$z + other$z)
    },
    subtract = function(other) {
      Vector3D(x = self$x - other$x, y = self$y - other$y, z = self$z - other$z)
    },
    scale = function(scalar) {
      Vector3D(x = self$x * scalar, y = self$y * scalar, z = self$z * scalar)
    },
    normalize = function() {
      magnitude <- sqrt(self$x^2 + self$y^2 + self$z^2)
      Vector3D(x = self$x / magnitude, y = self$y / magnitude, z = self$z / magnitude)
    }
  )
)

Matrix3x3 <- setRefClass("Matrix3x3",
  fields = list(data = "matrix"),
  methods = list(
    multiply_vector = function(vector) {
      x <- self$data[1, 1] * vector$x + self$data[1, 2] * vector$y + self$data[1, 3] * vector$z
      y <- self$data[2, 1] * vector$x + self$data[2, 2] * vector$y + self$data[2, 3] * vector$z
      z <- self$data[3, 1] * vector$x + self$data[3, 2] * vector$y + self$data[3, 3] * vector$z
      Vector3D(x = x, y = y, z = z)
    }
  )
)

Transformation <- setRefClass("Transformation",
  fields = list(matrix = "Matrix3x3"),
  methods = list(
    transform = function(vector) {
      self$matrix$multiply_vector(vector)
    }
  )
)

main <- function() {
  vector <- Vector3D$new(x = 1.0, y = 2.0, z = 3.0)
  matrix <- Matrix3x3$new(a11 = 1.0, a12 = 0.0, a13 = 0.0,
                          a21 = 0.0, a22 = 1.0, a23 = 0.0,
                          a31 = 0.0, a32 = 0.0, a33 = 1.0)
  transformation <- Transformation$new(matrix = matrix)
  transformed_vector <- transformation$transform(vector)
  cat('Original Vector: (', vector$x, ',', vector$y, ',', vector$z, ')\n')
  cat('Transformed Vector: (', transformed_vector$x, ',', transformed_vector$y, ',', transformed_vector$z, ')\n')
}

main()