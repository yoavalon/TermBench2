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
    scale = function(scalar) {
      Vector3D$new(self$x * scalar, self$y * scalar, self$z * scalar)
    },
    dot = function(other) {
      self$x * other$x + self$y * other$y + self$z * other$z
    },
    cross = function(other) {
      Vector3D$new(
        self$y * other$z - self$z * other$y,
        self$z * other$x - self$x * other$z,
        self$x * other$y - self$y * other$x
      )
    },
    magnitude = function() {
      sqrt(self$x^2 + self$y^2 + self$z^2)
    },
    normalize = function() {
      mag <- self$magnitude()
      if (mag > 0) {
        Vector3D$new(self$x / mag, self$y / mag, self$z / mag)
      } else {
        Vector3D$new(0, 0, 0)
      }
    }
  )
)

Transformation <- R6::R6Class("Transformation",
  public = list(
    rotation = NULL,
    translation = NULL,
    initialize = function(rotation, translation) {
      self$rotation <- rotation
      self$translation <- translation
    },
    apply = function(vector) {
      rotated <- self$rotate(vector)
      rotated$add(self$translation)
    },
    rotate = function(vector) {
      x <- vector$x
      y <- vector$y
      z <- vector$z
      cos_theta <- cos(self$rotation)
      sin_theta <- sin(self$rotation)
      rx <- x * cos_theta - z * sin_theta
      ry <- y
      rz <- x * sin_theta + z * cos_theta
      Vector3D$new(rx, ry, rz)
    }
  )
)

transform_sequence <- function(vectors, transformations) {
  result <- list()
  for (vector in vectors) {
    transformed <- vector
    for (transformation in transformations) {
      transformed <- transformation$apply(transformed)
    }
    result <- c(result, list(transformed))
  }
  return(result)
}

main <- function() {
  vectors <- list(Vector3D$new(1, 0, 0), Vector3D$new(0, 1, 0), Vector3D$new(0, 0, 1))
  transformations <- list(
    Transformation$new(pi / 4, Vector3D$new(1, 1, 1)),
    Transformation$new(pi / 6, Vector3D$new(-1, -1, -1))
  )
  while (TRUE) {
    transformed_vectors <- transform_sequence(vectors, transformations)
    for (v in transformed_vectors) {
      cat(sprintf('(%f, %f, %f)\n', v$x, v$y, v$z))
    }
  }
}

main()