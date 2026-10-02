r
Vector3D <- function(x, y, z) {
  self <- list(x = x, y = y, z = z)
  self$add <- function(other) {
    Vector3D(self$x + other$x, self$y + other$y, self$z + other$z)
  }
  self$subtract <- function(other) {
    Vector3D(self$x - other$x, self$y - other$y, self$z - other$z)
  }
  self$scale <- function(scalar) {
    Vector3D(self$x * scalar, self$y * scalar, self$z * scalar)
  }
  self$magnitude <- function() {
    sqrt(self$x^2 + self$y^2 + self$z^2)
  }
  self
}

Transformation <- function(rotation_matrix, translation_vector) {
  self <- list(rotation_matrix = rotation_matrix, translation_vector = translation_vector)
  self$apply <- function(vector) {
    x <- vector$x * self$rotation_matrix[1, 1] + vector$y * self$rotation_matrix[1, 2] + vector$z * self$rotation_matrix[1, 3]
    y <- vector$x * self$rotation_matrix[2, 1] + vector$y * self$rotation_matrix[2, 2] + vector$z * self$rotation_matrix[2, 3]
    z <- vector$x * self$rotation_matrix[3, 1] + vector$y * self$rotation_matrix[3, 2] + vector$z * self$rotation_matrix[3, 3]
    translated_vector <- Vector3D(x, y, z)$add(self$translation_vector)
    translated_vector
  }
  self
}

generate_sequence <- function(start, transformation, steps) {
  sequence <- list()
  current_vector <- start
  for (i in 1:steps) {
    sequence[[i]] <- current_vector
    current_vector <- transformation$apply(current_vector)
  }
  sequence
}

main <- function() {
  start_vector <- Vector3D(1, 0, 0)
  rotation_matrix <- matrix(c(0, -1, 0, 1, 0, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  translation_vector <- Vector3D(1, 1, 1)
  transformation <- Transformation(rotation_matrix, translation_vector)
  sequence <- generate_sequence(start_vector, transformation, 10)
  for (vector in sequence) {
    cat("(", vector$x, ", ", vector$y, ", ", vector$z, ")\n")
  }
}

main()