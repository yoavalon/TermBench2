library(dplyr)

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
    subtract = function(other) {
      Vector3D$new(self$x - other$x, self$y - other$y, self$z - other$z)
    },
    scale = function(factor) {
      Vector3D$new(self$x * factor, self$y * factor, self$z * factor)
    },
    rotate = function(angle, axis) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      if (axis == 'x') {
        Vector3D$new(self$x, self$y * cos_a - self$z * sin_a, self$y * sin_a + self$z * cos_a)
      } else if (axis == 'y') {
        Vector3D$new(self$x * cos_a + self$z * sin_a, self$y, -self$x * sin_a + self$z * cos_a)
      } else if (axis == 'z') {
        Vector3D$new(self$x * cos_a - self$y * sin_a, self$x * sin_a + self$y * cos_a, self$z)
      }
    }
  )
)

Transformation <- R6::R6Class("Transformation",
  public = list(
    translation = NULL,
    rotation = NULL,
    scale = NULL,
    initialize = function(translation, rotation, scale) {
      self$translation <- translation
      self$rotation <- rotation
      self$scale <- scale
    },
    apply = function(vector) {
      vector <- vector$add(self$translation)
      for (axis in names(self$rotation)) {
        angle <- self$rotation[[axis]]
        vector <- vector$rotate(angle, axis)
      }
      vector <- vector$scale(self$scale)
      return(vector)
    }
  )
)

GeometryTransformer <- R6::R6Class("GeometryTransformer",
  public = list(
    transformations = NULL,
    initialize = function(transformations) {
      self$transformations <- transformations
    },
    process = function(initial_vector) {
      current_vector <- initial_vector
      for (transformation in self$transformations) {
        current_vector <- transformation$apply(current_vector)
      }
      return(current_vector)
    }
  )
)

main <- function() {
  initial_vector <- Vector3D$new(1, 0, 0)
  transformations <- list(
    Transformation$new(Vector3D$new(0, 0, 0), list(x = 1.57), 2),
    Transformation$new(Vector3D$new(1, 1, 1), list(y = 1.57), 0.5),
    Transformation$new(Vector3D$new(0, 0, 0), list(z = 1.57), 1)
  )
  transformer <- GeometryTransformer$new(transformations)
  while (TRUE) {
    transformed_vector <- transformer$process(initial_vector)
    cat(sprintf('Transformed Vector: (%f, %f, %f)\n', transformed_vector$x, transformed_vector$y, transformed_vector$z))
  }
}

main()