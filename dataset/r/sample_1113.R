library(math)

Coordinate <- R6::R6Class("Coordinate",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    scale = function(factor) {
      Coordinate$new(self$x * factor, self$y * factor, self$z * factor)
    },
    rotate_x = function(angle) {
      y <- self$y * cos(angle) - self$z * sin(angle)
      z <- self$y * sin(angle) + self$z * cos(angle)
      Coordinate$new(self$x, y, z)
    },
    rotate_y = function(angle) {
      x <- self$x * cos(angle) + self$z * sin(angle)
      z <- -self$x * sin(angle) + self$z * cos(angle)
      Coordinate$new(x, self$y, z)
    },
    rotate_z = function(angle) {
      x <- self$x * cos(angle) - self$y * sin(angle)
      y <- self$x * sin(angle) + self$y * cos(angle)
      Coordinate$new(x, y, self$z)
    }
  )
)

Transform <- R6::R6Class("Transform",
  public = list(
    coord = NULL,
    initialize = function(coord) {
      self$coord <- coord
    },
    apply_transform = function(scale_factor, angles) {
      new_coord <- self$coord
      new_coord <- new_coord$scale(scale_factor)
      for (angle in angles) {
        new_coord <- new_coord$rotate_x(angle)
        new_coord <- new_coord$rotate_y(angle)
        new_coord <- new_coord$rotate_z(angle)
      }
      new_coord
    }
  )
)

recursive_transform <- function(transform, scale_factor, angles, depth) {
  new_coord <- transform$apply_transform(scale_factor, angles)
  cat(sprintf("Depth %d: %.2f, %.2f, %.2f\n", depth, new_coord$x, new_coord$y, new_coord$z))
  recursive_transform(Transform$new(new_coord), scale_factor, angles, depth + 1)
}

main <- function() {
  initial_coord <- Coordinate$new(1, 1, 1)
  initial_transform <- Transform$new(initial_coord)
  angles <- c(pi / 4, pi / 8, pi / 16)
  recursive_transform(initial_transform, 1.5, angles, 0)
}

main()