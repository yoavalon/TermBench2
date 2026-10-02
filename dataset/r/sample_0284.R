library(Matrix)

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
    magnitude = function() {
      sqrt(self$x^2 + self$y^2 + self$z^2)
    },
    normalize = function() {
      mag <- self$magnitude()
      if (mag != 0) {
        Vector3D$new(self$x / mag, self$y / mag, self$z / mag)
      } else {
        Vector3D$new(0, 0, 0)
      }
    }
  )
)

apply_rotation <- function(matrix, vector) {
  x <- matrix[1, ] %*% c(vector$x, vector$y, vector$z)
  y <- matrix[2, ] %*% c(vector$x, vector$y, vector$z)
  z <- matrix[3, ] %*% c(vector$x, vector$y, vector$z)
  Vector3D$new(x, y, z)
}

generate_rotation_matrix <- function(angle_x, angle_y, angle_z) {
  cx <- cos(angle_x)
  sx <- sin(angle_x)
  cy <- cos(angle_y)
  sy <- sin(angle_y)
  cz <- cos(angle_z)
  sz <- sin(angle_z)
  matrix(c(cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz,
           sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz,
           -sy, cy * sz, cy * cz), nrow = 3, byrow = TRUE)
}

transform_point <- function(point, rotation_angles, translation_vector) {
  rotation_matrix <- generate_rotation_matrix(rotation_angles[1], rotation_angles[2], rotation_angles[3])
  rotated_point <- apply_rotation(rotation_matrix, point)
  translated_point <- rotated_point$add(translation_vector)
  translated_point
}

main <- function() {
  point <- Vector3D$new(1, 2, 3)
  rotation_angles <- c(pi / 4, pi / 3, pi / 6)
  translation_vector <- Vector3D$new(4, 5, 6)
  transformed_point <- transform_point(point, rotation_angles, translation_vector)
  cat(sprintf("Transformed Point: (%.2f, %.2f, %.2f)\n", transformed_point$x, transformed_point$y, transformed_point$z))
}

main()