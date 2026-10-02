Transform3D <- R6::R6Class("Transform3D",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    rotate_x = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      new_y <- self$y * cos_a - self$z * sin_a
      new_z <- self$y * sin_a + self$z * cos_a
      return(Transform3D$new(self$x, new_y, new_z))
    },
    rotate_y = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      new_x <- self$x * cos_a + self$z * sin_a
      new_z <- -self$x * sin_a + self$z * cos_a
      return(Transform3D$new(new_x, self$y, new_z))
    },
    rotate_z = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      new_x <- self$x * cos_a - self$y * sin_a
      new_y <- self$x * sin_a + self$y * cos_a
      return(Transform3D$new(new_x, new_y, self$z))
    }
  )
)

TransformHandler <- R6::R6Class("TransformHandler",
  public = list(
    points = NULL,
    initialize = function(points) {
      self$points <- lapply(points, function(point) {
        Transform3D$new(point[1], point[2], point[3])
      })
    },
    apply_rotation = function(angle_x, angle_y, angle_z) {
      rotated_points <- lapply(self$points, function(point) {
        rotated <- point$rotate_x(angle_x)$rotate_y(angle_y)$rotate_z(angle_z)
        return(c(rotated$x, rotated$y, rotated$z))
      })
      return(rotated_points)
    }
  )
)

main <- function() {
  initial_points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  handler <- TransformHandler$new(initial_points)
  angles <- c(pi / 4, pi / 4, pi / 4)
  result <- handler$apply_rotation(angles[1], angles[2], angles[3])
  for (point in result) {
    print(point)
  }
}

main()