library(methods)

# Define the Point class
Point <- setRefClass("Point",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    initialize = function(x, y, z) {
      .self$x <- x
      .self$y <- y
      .self$z <- z
    },
    translate = function(dx, dy, dz) {
      .self$x <- .self$x + dx
      .self$y <- .self$y + dy
      .self$z <- .self$z + dz
    },
    scale = function(sx, sy, sz) {
      .self$x <- .self$x * sx
      .self$y <- .self$y * sy
      .self$z <- .self$z * sz
    },
    rotate_x = function(angle) {
      cos_angle <- cos(angle)
      sin_angle <- sin(angle)
      .self$y <- .self$y * cos_angle - .self$z * sin_angle
      .self$z <- .self$y * sin_angle + .self$z * cos_angle
    },
    rotate_y = function(angle) {
      cos_angle <- cos(angle)
      sin_angle <- sin(angle)
      .self$x <- .self$x * cos_angle + .self$z * sin_angle
      .self$z <- -.self$x * sin_angle + .self$z * cos_angle
    },
    rotate_z = function(angle) {
      cos_angle <- cos(angle)
      sin_angle <- sin(angle)
      .self$x <- .self$x * cos_angle - .self$y * sin_angle
      .self$y <- .self$x * sin_angle + .self$y * cos_angle
    }
  )
)

# Define the Transformation class
Transformation <- setRefClass("Transformation",
  fields = list(points = "list"),
  methods = list(
    initialize = function(points) {
      .self$points <- points
    },
    apply_translation = function(dx, dy, dz) {
      for (point in .self$points) {
        point$translate(dx, dy, dz)
      }
    },
    apply_scale = function(sx, sy, sz) {
      for (point in .self$points) {
        point$scale(sx, sy, sz)
      }
    },
    apply_rotation_x = function(angle) {
      for (point in .self$points) {
        point$rotate_x(angle)
      }
    },
    apply_rotation_y = function(angle) {
      for (point in .self$points) {
        point$rotate_y(angle)
      }
    },
    apply_rotation_z = function(angle) {
      for (point in .self$points) {
        point$rotate_z(angle)
      }
    }
  )
)

# Main function
main <- function() {
  points <- list(Point$new(1, 2, 3), Point$new(4, 5, 6), Point$new(7, 8, 9))
  transformation <- Transformation$new(points)
  transformation$apply_translation(1, 1, 1)
  transformation$apply_scale(2, 2, 2)
  transformation$apply_rotation_x(pi / 4)
  transformation$apply_rotation_y(pi / 4)
  transformation$apply_rotation_z(pi / 4)
  for (point in points) {
    cat("(", point$x, ", ", point$y, ", ", point$z, ")\n", sep = "")
  }
}

# Call the main function
main()