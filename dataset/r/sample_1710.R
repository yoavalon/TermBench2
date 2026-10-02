CoordinateTransformer <- R6::R6Class("CoordinateTransformer",
  public = list(
    points = list(),
    transformations = list(),
    add_point = function(x, y, z) {
      self$points <<- c(self$points, list(c(x, y, z)))
    },
    apply_rotation = function(angle_x, angle_y, angle_z) {
      cos_x <- cos(angle_x)
      sin_x <- sin(angle_x)
      cos_y <- cos(angle_y)
      sin_y <- sin(angle_y)
      cos_z <- cos(angle_z)
      sin_z <- sin(angle_z)
      rotation_matrix <- matrix(c(cos_y * cos_z, cos_y * sin_z, -sin_y, sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y, cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y), nrow = 3, byrow = TRUE)
      new_points <- lapply(self$points, function(point) {
        new_x <- rotation_matrix[1, ] %*% point
        new_y <- rotation_matrix[2, ] %*% point
        new_z <- rotation_matrix[3, ] %*% point
        c(new_x, new_y, new_z)
      })
      self$points <<- new_points
    },
    apply_translation = function(dx, dy, dz) {
      new_points <- lapply(self$points, function(point) {
        c(point[1] + dx, point[2] + dy, point[3] + dz)
      })
      self$points <<- new_points
    }
  )
)

generate_points <- function() {
  points <- replicate(100, c(runif(1, -10, 10), runif(1, -10, 10), runif(1, -10, 10)), simplify = FALSE)
  return(points)
}

main <- function() {
  transformer <- CoordinateTransformer$new()
  points <- generate_points()
  for (point in points) {
    transformer$add_point(point[1], point[2], point[3])
  }
  transformer$apply_rotation(0.5, 0.3, 0.2)
  transformer$apply_translation(5, 5, 5)
  while (TRUE) {
    transformer$apply_rotation(0.01, 0.02, 0.03)
    transformer$apply_translation(0.1, 0.1, 0.1)
  }
}

main()