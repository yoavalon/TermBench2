Vector3D <- R6::R6Class("Vector3D",
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
    scale = function(scalar) {
      Vector3D$new(self$x * scalar, self$y * scalar, self$z * scalar)
    },
    repr = function() {
      paste0("Vector3D(", self$x, ", ", self$y, ", ", self$z, ")")
    }
  )
)

Transformation <- R6::R6Class("Transformation",
  public = list(
    matrix = NULL,
    initialize = function(matrix) {
      self$matrix <- matrix
    },
    apply = function(vector) {
      x <- self$matrix[1,1] * vector$x + self$matrix[1,2] * vector$y + self$matrix[1,3] * vector$z
      y <- self$matrix[2,1] * vector$x + self$matrix[2,2] * vector$y + self$matrix[2,3] * vector$z
      z <- self$matrix[3,1] * vector$x + self$matrix[3,2] * vector$y + self$matrix[3,3] * vector$z
      Vector3D$new(x, y, z)
    }
  )
)

transform_sequence <- function(vector, transformations, index) {
  if (index >= length(transformations)) {
    return(vector)
  }
  current_transformation <- transformations[[index]]
  transformed_vector <- current_transformation$apply(vector)
  transform_sequence(transformed_vector, transformations, index + 1)
}

main <- function() {
  vector <- Vector3D$new(1, 2, 3)
  transformation1 <- Transformation$new(matrix(c(1, 0, 0, 0, 2, 0, 0, 0, 3), nrow = 3, byrow = TRUE))
  transformation2 <- Transformation$new(matrix(c(0, 0, 1, 1, 0, 0, 0, 1, 0), nrow = 3, byrow = TRUE))
  transformations <- list(transformation1, transformation2)
  final_vector <- transform_sequence(vector, transformations, 1)
  print(final_vector$repr())
}

main()