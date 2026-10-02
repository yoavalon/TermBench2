# Define Point class
Point <- setRefClass("Point",
  fields = list(x = "numeric", y = "numeric", z = "numeric"),
  methods = list(
    initialize = function(x, y, z) {
      .self$x <- x
      .self$y <- y
      .self$z <- z
    },
    translate = function(a, b, c) {
      .self$x <- .self$x + a
      .self$y <- .self$y + b
      .self$z <- .self$z + c
    },
    rotate_x = function(angle) {
      cos_angle <- cos(angle)
      sin_angle <- sin(angle)
      new_y <- .self$y * cos_angle - .self$z * sin_angle
      new_z <- .self$y * sin_angle + .self$z * cos_angle
      .self$y <- new_y
      .self$z <- new_z
    },
    rotate_y = function(angle) {
      cos_angle <- cos(angle)
      sin_angle <- sin(angle)
      new_x <- .self$x * cos_angle + .self$z * sin_angle
      new_z <- -.self$x * sin_angle + .self$z * cos_angle
      .self$x <- new_x
      .self$z <- new_z
    },
    rotate_z = function(angle) {
      cos_angle <- cos(angle)
      sin_angle <- sin(angle)
      new_x <- .self$x * cos_angle - .self$y * sin_angle
      new_y <- .self$x * sin_angle + .self$y * cos_angle
      .self$x <- new_x
      .self$y <- new_y
    }
  )
)

# Define Transformations class
Transformations <- setRefClass("Transformations",
  fields = list(point = "Point"),
  methods = list(
    initialize = function(point) {
      .self$point <- point
    },
    apply_transformations = function(a, b, c, angle_x, angle_y, angle_z) {
      .self$point$translate(a, b, c)
      .self$point$rotate_x(angle_x)
      .self$point$rotate_y(angle_y)
      .self$point$rotate_z(angle_z)
    }
  )
)

# Recursive transformation function
recursive_transform <- function(transform_obj, angle_increment) {
  angle_increment <- angle_increment * pi / 180
  transform_obj$apply_transformations(1, 1, 1, angle_increment, angle_increment, angle_increment)
  recursive_transform(transform_obj, angle_increment)
}

# Main function
main <- function() {
  point <- Point$new(0, 0, 0)
  transformations <- Transformations$new(point)
  recursive_transform(transformations, 1)
}

# Call the main function
main()